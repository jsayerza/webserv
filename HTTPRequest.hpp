#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <map>

class HTTPRequest {
private:
    std::string _method;        // GET, POST, DELETE
    std::string _uri;           // /index.html, /upload
    std::string _version;       // HTTP/1.1
    std::map<std::string, std::string> _headers;  // Host, Content-Type, etc.
    std::string _body;          // Cuerpo del request (para POST)
    bool _valid;                // Si el parsing fue exitoso
    std::string _errorMsg;      // Mensaje de error si parsing falla

public:
    // Constructor
    HTTPRequest();
    
    // Destructor
    ~HTTPRequest();
    
    // Parsear un request HTTP raw
    bool parse(const std::string& rawRequest);
    
    // Getters
    std::string getMethod() const;
    std::string getUri() const;
    std::string getVersion() const;
    std::string getHeader(const std::string& key) const;
    std::string getBody() const;
    bool isValid() const;
    std::string getErrorMsg() const;
    
    // Helpers
    bool hasHeader(const std::string& key) const;
    size_t getContentLength() const;
    
    // Debug
    void print() const;

private:
    // Métodos auxiliares para el parsing
    bool _parseRequestLine(const std::string& line);
    bool _parseHeaders(const std::string& headerSection);
    void _parseBody(const std::string& bodySection);
    std::string _trim(const std::string& str) const;
};

#endif