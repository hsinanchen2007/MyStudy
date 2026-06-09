![7.mp4](face1499-cb63-49d2-acd9-8372853fcb9e)

<![1.jpg](https://pic.leetcode-cn.com/c02baf6b6e4a439885f75c452060bfb5809a094d30d8fc518505d6050ea7daf2-1.jpg),![2.jpg](https://pic.leetcode-cn.com/49a5978411190e3032b4d1a246202265ae50dc98312d37007495d1f5e9fc1a13-2.jpg),![3.jpg](https://pic.leetcode-cn.com/da7ea1217b6f2ed8a3d6198dfd18458192b5d1aabb6de819d3613a365452de1b-3.jpg),![1.jpg](https://pic.leetcode-cn.com/37edeb8b8c27b42bd6844627320469e4dcd1a48470c1353a31bdadaf71d82813-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c40e2bbcef0c64b99239bddcffec1318f1280f927da483d6a23e9ea48229aa69-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b7b5dc5ab83d00237169142a03ca02f93cebde5eeb9c10e972ba4e59728bd37b-3.jpg),![4.jpg](https://pic.leetcode-cn.com/515cd55dcfbfba1e8acb4b2808b0f0dca4d63c3c77361a17abbbc74b6173f830-4.jpg),![5.jpg](https://pic.leetcode-cn.com/909eb1b560436f8547d80e4fee3d1fa3f5089ef4d3254fca8f226bfcf21b6ca7-5.jpg)>

```
class Solution
{
public:
    int reverse(int x)
    {
        long result; //利用long避免溢出
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }
        stringstream ss;
        ss << x;
        string tmpStr;
        ss >> tmpStr;

        int tmpStrSize = int(tmpStr.size());
        string resultStr;
        for (int index = tmpStrSize - 1; index >= 0; index--)
        {
            resultStr.push_back(tmpStr[index]);
        }
        ss.clear(); //使用前记得clear
        ss << resultStr;
        ss >> result;
        if (result > INT_MAX)
        {
            return 0;
        }
        return int(result);
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/3d253e77b8c47ef35c882c05788fce296fbadd2538da0c0e925af56cf5cc6063-1.jpg),![2.jpg](https://pic.leetcode-cn.com/a849e085e2cf334723c06f52baa30815decc5bdd378636ad98f11ef808ed0bf8-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b60ff88df9f6846fc2567b5d1cd54d202e59d4e67e51169bb7e352cd8824c90d-3.jpg),![1.jpg](https://pic.leetcode-cn.com/708603a71c382a9f3cbdb3b0ecf9bca233a287088474980870710da6ee77a3c0-1.jpg),![2.jpg](https://pic.leetcode-cn.com/e0470f173939df01c340bae3272f8d4c5f539eabbefe5c4ca073d49717a87e86-2.jpg),![3.jpg](https://pic.leetcode-cn.com/8221a763e133d8e818c5d16bd26b0a5738322ffea08e0f6767093cbbb1cef3a5-3.jpg),![4.jpg](https://pic.leetcode-cn.com/76cccdd860e2d997bc646955547c8d5cc02f4b3eeb700874a9c51a617b4d7039-4.jpg),![5.jpg](https://pic.leetcode-cn.com/9d460b261dfd0d73c4598b67464ff5559b73963d9b5a9fe84db615d482c548f3-5.jpg)>

```
class Solution
{
public:
    int reverse(int x)
    {
        long result(0); //利用long避免溢出
        if (x == INT_MIN)
        {
            return 0;
        }
        if (x < 0)
        {
            return -reverse(-x);
        }

        int digit(0);
        while (x > 0)
        {
            digit = x % 10;
            x /= 10;
            result = result * 10 + digit;
        }

        if (result > INT_MAX)
        {
            return 0;
        }
        return int(result);
    }
};
```

![结局.jpg](https://pic.leetcode-cn.com/9bc52118cca9cfb47720b6e43a26c300445cc457749c518a91cab269e0c86cca-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75329552
