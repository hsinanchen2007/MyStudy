### 解题思路
![image.png](https://pic.leetcode-cn.com/8f4587514978b78206fd78bf261b7986758ecb49808b7c78636cc489de20be75-image.png)
不知道这么做违不违法
### 代码

```cpp
class Solution {
public:
    vector<int> getHours(int n)
    {
        vector<int> res;
        switch(n)
        {
            case 0:
                res.push_back(0);
                break;
            case 1:
                res.push_back(1);
                res.push_back(2);
                res.push_back(4);
                res.push_back(8);
                break;
            case 2:
                res.push_back(3);
                res.push_back(5);
                res.push_back(6);
                res.push_back(9);
                res.push_back(10);
                break;
            case 3:
                res.push_back(7);
                res.push_back(11);
                break;
            default:
                break;
        }
        return res;
    }
    vector<int> getMins(int n)
    {
        vector<int> res;
        switch(n)
        {
            case 0:
                res.push_back(0);
                break;
            case 1:
                res.push_back(1);
                res.push_back(2);
                res.push_back(4);
                res.push_back(8);
                res.push_back(16);
                res.push_back(32);
                break;
            case 2:
                res.push_back(3);
                res.push_back(5);
                res.push_back(9);
                res.push_back(17);
                res.push_back(33);
                res.push_back(6);
                res.push_back(10);
                res.push_back(18);
                res.push_back(34);
                res.push_back(12);
                res.push_back(20);
                res.push_back(36);
                res.push_back(24);
                res.push_back(40);
                res.push_back(48);
                break;
            case 3:
                res.push_back(7);
                res.push_back(11);
                res.push_back(19);
                res.push_back(35);
                res.push_back(13);
                res.push_back(21);
                res.push_back(37);
                res.push_back(25);
                res.push_back(41);
                res.push_back(49);
                res.push_back(14);
                res.push_back(22);
                res.push_back(38);
                res.push_back(26);
                res.push_back(42);
                res.push_back(50);
                res.push_back(28);
                res.push_back(44);
                res.push_back(56);
                res.push_back(52);
                break;
            case 4:
                res.push_back(15);
                res.push_back(23);
                res.push_back(39);
                res.push_back(27);
                res.push_back(43);
                res.push_back(51);
                res.push_back(29);
                res.push_back(53);
                res.push_back(30);
                res.push_back(54);
                res.push_back(58);
                res.push_back(46);
                res.push_back(45);
                res.push_back(57);
                break;
            case 5:
                res.push_back(31);
                res.push_back(47);
                res.push_back(55);
                res.push_back(59);
                break;
            default:
                break;
        }
        return res;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if (num > 8 || num < 0)
            return res;
        for (int i=0; i <= num && i <= 3; i++)
        {
            vector<int> hours;
            vector<int> mins;
            hours = getHours(i);
            mins = getMins(num-i);
            for (int m=0; m<hours.size(); m++)
                for (int n=0; n<mins.size(); n++)
                {
                    if (mins[n] >= 0 && mins[n] <10)
                        res.push_back(to_string(hours[m]) + ":0" + to_string(mins[n]));
                    else
                        res.push_back(to_string(hours[m]) + ":" + to_string(mins[n]));
                }
        }
        return res;
    }
};
```