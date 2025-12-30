#ifndef MIMETYPES_HPP
#define MIMETYPES_HPP

#include <string>
#include <map>

class MimeTypes {
private:
    static std::map<std::string, std::string> _types;
    static bool _initialized;
    
    static void _initTypes();

public:
    // Obtener MIME type según extensión de archivo
    static std::string getType(const std::string& extension);
    
    // Obtener MIME type desde un filepath completo
    static std::string getTypeFromPath(const std::string& filepath);
    
    // MIME type por defecto
    static std::string getDefault();

private:
    // Extraer extensión de un filepath
    static std::string _getExtension(const std::string& filepath);
};

#endif