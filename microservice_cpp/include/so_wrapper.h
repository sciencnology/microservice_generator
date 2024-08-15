#ifndef SO_WRAPPER_H
#define SO_WRAPPER_H

#include <map>
#include <string>
#include <boost/asio.hpp>
#include "nlohmann/json.hpp"
#include "util.hpp"

namespace asio = boost::asio;
using json = nlohmann::json;
using ProcessFunc = std::function<std::string(json &)>;
using ProcessCoroutine = std::function<asio::awaitable<std::string>(json &)>;
using ProcessFuncMap = std::map<std::string, std::map<std::string, ProcessFunc>>;
using ProcessCoroutineMap = std::map<std::string, std::map<std::string, ProcessCoroutine>>;

class SoWrapper : util::Singleton<SoWrapper>
{
public:
private:
};

#ifdef __cplusplus
extern "C"
{
#endif

    void init_process_map(ProcessFuncMap &func_map, ProcessCoroutineMap &coroutine_map);

#ifdef __cplusplus
}
#endif

#endif // SO_WRAPPER_H