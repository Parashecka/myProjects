#pragma once

#include<string>
#include<memory>
#include<map>
namespace Renderer {
	class ShaderProgram;
	class Texture2D;
}
class ResourceManager {
public:
	
	ResourceManager(const std::string & executablePath);	
	~ResourceManager() = default;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator  = (const ResourceManager&) = delete;
	ResourceManager& operator  = (ResourceManager&&) = delete;
	ResourceManager(ResourceManager&&) = delete;

	static std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
	static std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& shaderName);
	static std::shared_ptr<Renderer::Texture2D> loadTexture(const std::string& textureName, const std::string& texturePath);
	static std::shared_ptr<Renderer::Texture2D> getTexture(const std::string& textureName);


private:
	static std::string getFileString(const std::string& relativeFilePath);

	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramsMap;
	static ShaderProgramsMap m_shaderPrograms;

	typedef std::map<const std::string, std::shared_ptr<Renderer::Texture2D>> TexturesMap;
	static TexturesMap m_textures;

	static std::string m_path;
};