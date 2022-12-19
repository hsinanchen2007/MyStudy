![17.mp4](4d3edf78-672e-4d27-98f2-e7f57b65d405)

<![1.jpg](https://pic.leetcode-cn.com/0b442a881f02319ed184e8a672722bf4ce08752c234ff83bd3d41fb35e45cbb1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/aff053342bbdc28d79931f05e17239db74df6ddf17c93f8ba7c924520b604eab-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c5c2c7da0b60158dceb9c44d8bbc547106ac6b6d2f17b4657e05886e04a6fa08-3.jpg),![1.jpg](https://pic.leetcode-cn.com/8e7d827d06609089841a779b4a20f3ae641665df5aaff43e02b7acd90a822823-1.jpg),![2.jpg](https://pic.leetcode-cn.com/5d291e948258db4c9718fec492c507f4ff746f6814f1c4f3c7ea41a4c1c83848-2.jpg),![3.jpg](https://pic.leetcode-cn.com/56b27bddc7d3d79109f9290bbfb8bcac922ed3e4dc211b701cc1538d1e242bc2-3.jpg),![4.jpg](https://pic.leetcode-cn.com/bd282ba6f003ba6d306c43dfa12652118df94bf021189d94a559f1cd093ae4f2-4.jpg),![5.jpg](https://pic.leetcode-cn.com/825e207b16eb9cd21dfe5f64d825faaddd057dab33c84e8b98d5eab631f419ad-5.jpg),![6.jpg](https://pic.leetcode-cn.com/56c13f315f6ded389ebe34f3d5df009c4a6f20f965b3fdb6c07bd339f8035a24-6.jpg)>

```cpp [-C++]
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<string> result;
    string digits;
    unordered_map<char, string> store;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return result;
        }
        this->digits = digits;
        //储存字典
        store = unordered_map<char, string>{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        dfs("", 0);
        return result;
    }

    void dfs(string resultStr, int index)
    {
        int digitsSize = int(this->digits.size());
        if (digitsSize == index)
        {
            result.push_back(resultStr);
            return;
        }
        char targetChar = this->digits[index];
        string targetStr = store[targetChar];
        for (auto tmpChar : targetStr)
        {
            dfs(resultStr + tmpChar, index + 1);//递归调用
        }
        return;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/21546379af3b3d573b81231ca1b059403868feace201ad96b9b07697529a7879-1.jpg),![2.jpg](https://pic.leetcode-cn.com/824419713d622420e2c54ed8da9b8d8e870d672081d187734b351a66a154b56a-2.jpg),![3.jpg](https://pic.leetcode-cn.com/661e4229323782535acedfe213ca77e79d098aec8976336b988a76e84799c07e-3.jpg),![1.jpg](https://pic.leetcode-cn.com/c8b15b3f41c0c917e10fe9ef358acae84b2eec127d308cad5e3fe99b6ed0bd08-1.jpg),![2.jpg](https://pic.leetcode-cn.com/201dc24980c618aad0e6b91f264503b37a8cec01c526e8773360cc8b57270c3d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/9cdd55d05c611aa9e3fd9e2b21bab0a5fd40c4e8f9975092fb63e386193777b7-3.jpg),![4.jpg](https://pic.leetcode-cn.com/f4dacb23585fe5e777b2024dbc9d3f03c9f026af017c31aa7aba3f20e0e13f49-4.jpg),![5.jpg](https://pic.leetcode-cn.com/17354569548aa1f32737a11abc006b1f0bcea9ed7262633c090cde5883e97d4f-5.jpg),![6.jpg](https://pic.leetcode-cn.com/e8962d43a37fb56b2ffaafc5f04d90dfbb5095b15401d8f2c102dda5139ae76e-6.jpg),![7.jpg](https://pic.leetcode-cn.com/77a8c3784bed0a031a13c9832d14d4ca9d3fa4a9eff8d72b09b1611a1f66f26c-7.jpg)>

```cpp [-C++]
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
    vector<string> result;
    string digits;
    unordered_map<char, string> store;

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return result;
        }
        this->digits = digits;
        //储存字典
        store = unordered_map<char, string>{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        queue<string> workQueue;
        workQueue.push("");
        for (auto targetChar : digits)
        {
            string targetStr = store[targetChar];
            int queueSize = int(workQueue.size());
            //当前层，进行添加字符
            for (int i = 0; i < queueSize; ++i)
            {
                string tmpStr = workQueue.front();
                workQueue.pop();
                for (auto tmpChar : targetStr)
                {
                    workQueue.push(tmpStr + tmpChar);
                }
            }
        }
        while (!workQueue.empty())
        {
            string tmpStr = workQueue.front();
            workQueue.pop();
            result.push_back(tmpStr);
        }
        return result;
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/0974263057950f07fbffc99ef4276bb7cef0b63979a9f184dbe4693610805898-%E7%BB%93%E5%B1%80.jpg)
如果你喜欢该回答，希望你能点我的头像关注一下，日更题解哦~
视频地址：
https://www.bilibili.com/video/av76270924



