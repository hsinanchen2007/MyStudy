![20.mp4](22094c77-7625-483d-a256-31f61407a916)

<![1.jpg](https://pic.leetcode-cn.com/883bd1f0013e063bc738a511c94dbcf56011a1f807f9198cb034a080df3e89a4-1.jpg),![2.jpg](https://pic.leetcode-cn.com/5108fdda6cea0b93417cad129279a89325f2d6efd6ce0a71be2c77b43fe7ea89-2.jpg),![3.jpg](https://pic.leetcode-cn.com/5daac21294557c006e3dc78d69e431079965666668b3e650f6c43ccb17e3f22c-3.jpg),![1.jpg](https://pic.leetcode-cn.com/3df05589ac4f4a645fe7e5bd4c93835ad17ecaa7beefe144a7d40199670023c1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/e4b08b7e5351eb9ea59e6550cfa8ec886400237c0de942433595ff688de8be10-2.jpg),![3.jpg](https://pic.leetcode-cn.com/5472b0ea1963cc586bb4b9683fba1e0ff5c86f3dd11773245aaeeacd8ffff40a-3.jpg),![4.jpg](https://pic.leetcode-cn.com/c0d9d2c99047246dc70644b09c1fb0c169991726ecc442fc6078face669a910c-4.jpg),![5.jpg](https://pic.leetcode-cn.com/a8cb28bcbf708c460320d84ace657d8c20783d3653245b14994f52ca450f8238-5.jpg),![6.jpg](https://pic.leetcode-cn.com/c918a7e2f3894c01aed6528782496b1ec1b0a7def53e2c85353437aa39ea4a8b-6.jpg),![7.jpg](https://pic.leetcode-cn.com/97b6d1a21fe850ef222dae7f121b109f61144b72faf5144d4426ed028a93c474-7.jpg),![8.jpg](https://pic.leetcode-cn.com/8b8771eb0392ea20c00b85f1331f7b2994177117fabfea662aafa1707feac176-8.jpg)>

```cpp [-C++]
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> store;
        auto strSize = s.size();
        if(strSize % 2 == 1){
            return false;
        }
        for (auto tmpChar : s)
        {
            char popChar = ' ';
            switch (tmpChar)
            {
            //如果是(,[,{,就压入栈中
            case '(':
            case '[':
            case '{':
                store.push(tmpChar);
                break;
            case ')':
                //注意栈为空的情况
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '(')
                {
                    return false;
                }
                break;
            case ']':
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '[')
                {
                    return false;
                }
                break;
            case '}':
                if (store.empty())
                {
                    return false;
                }
                popChar = store.top();
                store.pop();
                if (popChar != '{')
                {
                    return false;
                }
                break;
            default:
                return false;
                break;
            }
        }
        if (store.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/8f4dfd175d972bcf82fc047e0fec6335e078ea38751cce31ebca4c6021c80089-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76508099