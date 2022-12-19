### 解题思路
创建一个数组用来存储每个字母出现的次数。
一旦这个数字大于1，就返回假。
如果遍历整个字符串后依然没有出现上述情况，就返回真。
附上JAVA和C++代码:

### 代码

```java []
class Solution {
    public boolean isUnique(String astr) {
        int count[]=new int[26];
        for(int i=0;i<astr.length();i++)
        {
            count[astr.charAt(i)-97]++;
            if(count[astr.charAt(i)-97]>1)return false;//出现两次
        }
        return true;
    }
}
```

```C++ []
class Solution {
public:
    bool isUnique(string astr) {
        int jishu[26]={0};
        for(int i=0;astr[i]!='\0';i++)
        {
            jishu[astr[i]-97]++;
            if(jishu[astr[i]-97]>1)return false;//出现两次
        }
        return true;
    }
};
```

![boke.PNG](https://pic.leetcode-cn.com/fe01ac6ee8a68760de407034916b691d6dedf1f4abfd440cfbae5d92b8809b50-boke.PNG)
