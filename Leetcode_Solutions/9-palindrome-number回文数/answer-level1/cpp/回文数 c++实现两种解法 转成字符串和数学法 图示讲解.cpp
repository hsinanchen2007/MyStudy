![9.mp4](b9d1df65-eab1-44c4-b95e-df723a432962)

<![1.jpg](https://pic.leetcode-cn.com/49186ba5f31aa705a6db849b7dc20513e4aa216232d08f0cb8d62248c7dbebe1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/d2b42f968858090565bd8780b29e6223a0a0f0cd50013322e1743052049769ac-2.jpg),![3.jpg](https://pic.leetcode-cn.com/022189d6e07b9cc6d814e226d0575f6326eed5d9a878855baf9069957f605230-3.jpg),![1.jpg](https://pic.leetcode-cn.com/6e1b0b2765a89d21869d7fd10bf43cca5b3b2ba18cc63a6584c09a48c3dd55e9-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c203132e6a51171dcbc83173fb488ad3a435b6aabc349fed2a13501c0d1adc61-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b7672bd675c92ce0c78e164600621848d1d01d1cf65a2a0f008ef0d8544928a3-3.jpg),![4.jpg](https://pic.leetcode-cn.com/8e5b357f39f654507bc51dbb1d719018e44ac54f3e3cf93c04cc0cf86d2db91a-4.jpg)>

```
class Solution
{
public:
    bool isPalindrome(int x)
    {
        bool result;
        if (x < 0)
        {
            return false;
        }
        stringstream ss;
        ss << x;
        string str, reversedStr;
        ss >> str;

        int strSize = int(str.size());
        for (int index = strSize - 1; index >= 0; index--)
        {
            reversedStr.push_back(str[index]);
        }
        result = str == reversedStr;
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/4718c3a99eb2bbf3b406f1cb7a1ad46429903841290fc1fbc313798c99297302-1.jpg),![2.jpg](https://pic.leetcode-cn.com/9a70c9058b218ee28df156834c4a74c176515013768260363429aa2e70f1cb37-2.jpg),![3.jpg](https://pic.leetcode-cn.com/21424feebeb9d7ddb2b97dca0e0a1cce5211b4a632830d9a1c3fa262b910cc62-3.jpg),![1.jpg](https://pic.leetcode-cn.com/4d6a36ea6e038d9b2f1b02592bc0304ec2887992ae99c01529472db98b532311-1.jpg),![2.jpg](https://pic.leetcode-cn.com/591ee945c0743c0783d9af21e66ed19960b6c040c92421d55b00dd15ec89ae1d-2.jpg),![3.jpg](https://pic.leetcode-cn.com/a4b0c3f3b389a6a5e861b3faa7293e32f8ab31ef46cc0156ccd984e2a2a4c2e4-3.jpg),![4.jpg](https://pic.leetcode-cn.com/d27bfba72933cd61e57c45052699e77ef20a3a5adc4f1f47bc97389e062c1d9f-4.jpg),![5.jpg](https://pic.leetcode-cn.com/87170926c91117112bf32bb20eb6946af9640cd55bbf0f590ba37521641416d1-5.jpg),![6.jpg](https://pic.leetcode-cn.com/b0ffd2aa2ade3eba5b45f2e4120801129a1414a2bc8d7ce8bfa47d5999026e01-6.jpg),![7.jpg](https://pic.leetcode-cn.com/10cc2f38328c3a50396bd66e29b3fd9d1b31e0c38914010caf9ba53d2fb868ee-7.jpg),![8.jpg](https://pic.leetcode-cn.com/8dce60a0244823c37144048acd002138f465909b2e323b10e201a7cfadf4352b-8.jpg),![9.jpg](https://pic.leetcode-cn.com/2f79ff03a6099bd59f9dcd5f97461f426ca9121c2f2e68f70bc8aa06bf174741-9.jpg)>

```
class Solution
{
public:
    bool isPalindrome(int x)
    {
        bool result;
        //避免例如x = 110的情况
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int reverseNumber = 0;
        //考虑一下为什么x = 21时，不会出错
        while (x > reverseNumber)
        {
            reverseNumber = reverseNumber * 10 + x % 10;
            x = x / 10;
        }
        //分别是偶数位和奇数位的情况
        result = (x == reverseNumber) || (x == reverseNumber / 10);
        return result;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/831427a7bdc2165ab5ae4b30b4753149b61f1273cf0d1a031472a4a02a6a5755-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75449979

