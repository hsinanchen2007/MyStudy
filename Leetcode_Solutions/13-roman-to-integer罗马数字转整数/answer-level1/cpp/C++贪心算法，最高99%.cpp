### 解题思路
仔细观察罗马数字的单位字符，发现其满足从大数与小数的头部不重叠，比如"M"和"CM"，M和C不相等。
由此使用贪心算法便没有了障碍。
{1000,900,500,400,100,90,50,40,10,9,5,4,1}
和
{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}
一一对应。
依次遍历，每出现一个对应罗马字符，就可以加上对应整数。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int arab(0);
        int length;
        string sub;
        
        int bit[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<13;i++){
            length=(int)str[i].size();
            sub=s.substr(0,length);
            while(sub==str[i]){
                arab+=bit[i];
                s=s.substr(length);
                sub=s.substr(0,length);
            }
        }
        
        return arab;
    }
};

```