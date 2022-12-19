![6.mp4](296a59a9-d0f9-4d39-a117-e6b9f84d2c1f)

<![1.jpg](https://pic.leetcode-cn.com/210255b3408a59fe32707aa5768d0f1314c6ca73db47add99b74a634ae91d286-1.jpg),![2.jpg](https://pic.leetcode-cn.com/548b8197e950e565610fcd15e6088c51b8dc598e363ef87dc0171f3e97120b7b-2.jpg),![3.jpg](https://pic.leetcode-cn.com/1737113b4b893ba827e6577787c314b86529da43988a52ee5c74bef5c309fa25-3.jpg),![1.jpg](https://pic.leetcode-cn.com/cfbf126034ba5c9ab0871c8be6807f6d114c568bc0ca6f42fbc0569c1a4a9a4c-1.jpg),![2.jpg](https://pic.leetcode-cn.com/d53a1f008c81d964548e7bce6bb61b915174c348675830edbd3d2e01d5e87a26-2.jpg),![3.jpg](https://pic.leetcode-cn.com/446d961928b195bf881cae3255690aff0ce829cb055c7cb15fc54533228efcd1-3.jpg),![4.jpg](https://pic.leetcode-cn.com/6854cc2aa91911e6ae099dae00ae9e9f3686b5d2fb375e7897506cc078e27316-4.jpg),![5.jpg](https://pic.leetcode-cn.com/64f576fb69e20569b45265224e4cc50a8ca2a15ea666eb6b393ce0e286d6b3d6-5.jpg),![6.jpg](https://pic.leetcode-cn.com/0a47c19560a4b9a8e27e3690cf4c98dc2326a5696559104e2c0abc625684f4cd-6.jpg),![7.jpg](https://pic.leetcode-cn.com/24e1b4e222f24377dd05d6eb7bb4df467431771633f12b6b9602a526d9ead9d1-7.jpg),![8.jpg](https://pic.leetcode-cn.com/d0aa756b457da25e568676f7771a63bfa96c0f9dc8c15e0d265e80263cbab873-8.jpg),![9.jpg](https://pic.leetcode-cn.com/7a9925ec8d1047bd89ff43defa8dd53eda2a3da9d2b165a9d2702119e2ae46c7-9.jpg),![10.jpg](https://pic.leetcode-cn.com/8bc232e19c6a4b447ed31be02d7c36171bdbff9f90688a651ea68f041f3cef45-10.jpg)>

```
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        int sSize = int(s.size());
        int storeSize = min(sSize, numRows);
        string result;
        vector<string> store(storeSize);
        int loc = 0;
        //初始有一次更改change值，因此初始值为false
        bool change = false;
        for (int index = 0; index < sSize; index++)
        {
            store[loc].push_back(s[index]);
            if (loc == numRows - 1 || loc == 0)
            {
                change = !change;
            }
            loc += change ? 1 : -1;
        }

        for (int index = 0; index < storeSize; index++)
        {
            result = result + store[index];
        }
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/1f9b61861f0d243ceeadd65fbb0689dfbec4ced186740b6e9b921178e510dece-1.jpg),![2.jpg](https://pic.leetcode-cn.com/dbc59ea3df21e70bbf4716e9b93b8135ccf112d7c3ebba82b12d0d7cb05e4367-2.jpg),![3.jpg](https://pic.leetcode-cn.com/766c00b35365254d38f53d230994de10733ea90854ee6d4d0595eae10a1e1ea4-3.jpg),![1.jpg](https://pic.leetcode-cn.com/fc5a6d206676a46f867740f0791bc72e7833c1c514cfc3c71bba87ef1b65a72a-1.jpg),![2.jpg](https://pic.leetcode-cn.com/0d7d566dc013ec731190cbd4ef4b5a9df367b9e5a12c9ad5ef0b7bf3c5a20bdd-2.jpg),![3.jpg](https://pic.leetcode-cn.com/3d5f05d8c76354b7e2df0e12407f76d0e6afa24d93b471b9a6026a9e492ee24e-3.jpg),![4.jpg](https://pic.leetcode-cn.com/26004073c508f993718d2c65a67a308f70269048a3c7f25b0b454eb026017430-4.jpg),![5.jpg](https://pic.leetcode-cn.com/5449f3659a480c4099011eb81087177205a15be53cb5db6d0a004bc391f469d3-5.jpg),![6.jpg](https://pic.leetcode-cn.com/f9e232a3cdcc110e21c752ee7224840b408a962b8dde4e8c42bb663dfecc0051-6.jpg),![7.jpg](https://pic.leetcode-cn.com/f32c82768a6d23712ec6c26a8aadf974bc1f7531d12cde0e66f3585b1b816e1b-7.jpg),![8.jpg](https://pic.leetcode-cn.com/b4bac9b43332a214f90d5447058fb984fa89f8f51917f99b4445b642da8aaf7e-8.jpg),![9.jpg](https://pic.leetcode-cn.com/c71b4b16c3d15417b297f820235b2bb495813cc091d19ed5baeccc146702528e-9.jpg),![10.jpg](https://pic.leetcode-cn.com/3aba337a7fad229e069e1d2298d584350194555570cdf5d450db8babd0a3400f-10.jpg)>

```
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        int sSize = int(s.size());
        string result;

        for (int index = 0; index < numRows; index++)
        {
            int length = 2 * numRows - 2;
            //头尾情况特殊考虑，length为周期
            if (index == 0 || index == numRows - 1)
            {
                for (int loc = index; loc < sSize; loc += length)
                {
                    result.push_back(s[loc]);
                }
            }
            else
            {
                //其他情况，初始时，left + right = length
                for (int left = index, right = length - index; left < sSize; left += length, right += length)
                {
                    result.push_back(s[left]);
                    if (right < sSize)
                    {
                        result.push_back(s[right]);
                    }
                }
            }
        }
        return result;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/3cb90c741298e29ef02b70e30bda5e03c597a66bfe355d013203ea23df0b5218-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75209867