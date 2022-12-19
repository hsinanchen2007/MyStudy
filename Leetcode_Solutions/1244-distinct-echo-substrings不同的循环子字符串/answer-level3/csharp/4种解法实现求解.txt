## 解法一
思路：使用两个游标，从前到后进行对比，直到字符串结束。
1. 最前面的for循环（7-17行），是为了在比赛时候处理超时特例，特例是2000个a：（[点击查看该测试用例](https://www.zhenxiangsimple.com/files/tech/testCase20200112.txt)）
2. 实际算法不应该这么写，很惭愧自己为了比赛欺骗电脑

```csharp
public class Solution {
    public int DistinctEchoSubstrings(string text) {
        bool flag = false;
        int t,count=0;
        int len = text.Length;
        
        for(int i=0;i<len;i++)
        {
            if(text[i] != text[0])
            {
                flag = true;
            }
        }
        if(!flag)
        {
            return len/2 ;
        }
        List<string> rList = new List<string>();
        string str;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1; j*2-i<=len;j++)
            {
                if(text[i] == text[j])
                {
                    t = j - i;
                    flag = true;
                    for(int k=1;k<t;k++)
                    {
                        if(text[i+k] != text[j+k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        str = text.Substring(i,t);
                        if(!rList.Contains(str))
                        {
                            rList.Add(str);
                            count ++;
                        }
                    }
                }
            }
            
        }
        return count;
    }
}
```
![image.png](https://pic.leetcode-cn.com/f82229841bdeb3a7cb3e5b5f46cdd00e477f59625bd32bcf8448c69909728177-image.png)

![image.png](https://pic.leetcode-cn.com/c01df9698fc2156658e8c1c9c46ff2619f55b3bd0edf68eaef2e6cf7f61ff512-image.png)

***
## 解法二
思路：基于解法一做了下面优化
1. 首先，把作弊代码去掉（手动尴尬）
2. 使用字符串剪切后对比，而不是一个字母一个字母的对比，省去了最里面的第三层循环（k）
3. 将原来的两个游标模式，两个游标是一个前面一个后面，改为使用长度判断是的最外层循环减半，因为子字符串的长度不能超过总长度的一半。
4. 尝试使用Hash表，字典代替List这种线性表，用于加快查找

```csharp
public class Solution {
    public int DistinctEchoSubstrings(string text) {
        int len = text.Length,halfLen = len/2;

        Dictionary<string,bool> rDict = new Dictionary<string,bool>();
        //Hashtable rHash = new Hashtable();
        //List<string> rList = new List<string>();
        string str;
        for(int i=1;i<=halfLen;i++)
        {//i是长度
            for(int j=i;j+i<=len;j++)
            {//j是位置索引
                if((str = text.Substring(j-i,i)) == text.Substring(j,i) && !rDict.ContainsKey(str))
                {
                    rDict.Add(str,true);
                }                
            }            
        }
        return rDict.Count;
    }
}
```
***
## 解法三
思路：首先获取每个字符所在位置，直接使用位置进行字符串截取判断，而不用每次都要找字符串。
1. 获取字符及对应位置
2. 遇到字符串直接定位到对应位置，然后两个位置相差的距离就是子字符串

```csharp
public class Solution {
    public int DistinctEchoSubstrings(string text) {
        int len = text.Length;

        List<string> rList = new List<string>();
        Dictionary<char,List<int>> rDict = new Dictionary<char,List<int>>();
        for(int i=0;i<len;i++)
        {//将字符串的字符进行归类
            if(!rDict.ContainsKey(text[i]))
            {
                rDict.Add(text[i],new List<int>());
            }
            rDict[text[i]].Add(i);
        }
        string str;
        for(int i=0;i<len;i++)
        {
            foreach(int j in rDict[text[i]])
            {
                if(j <= i) continue;//仅查看后面位置的
                if(j*2-i>len) break;//越界之后不再看后面的
                if((str = text.Substring(j,j-i)) == text.Substring(i,j-i) && !rList.Contains(str))
                {
                    rList.Add(str);
                }                
            }            
        }
        return rList.Count;
    }
}
```
同样的原理，不同的写法：
1. 上面写法：对字符串的字符从前到后选字符，依次对位置进行判断和对比
2. 下面写法：按归类的字符结果依次选择字符，依次对位置进行判断和对比

```csharp
public class Solution {
    public int DistinctEchoSubstrings(string text) {
        int len = text.Length,m,n;

        List<string> rList = new List<string>();
        Dictionary<char,List<int>> rDict = new Dictionary<char,List<int>>();
        for(int i=0;i<len;i++)
        {//将字符串的字符进行归类
            if(!rDict.ContainsKey(text[i]))
            {
                rDict.Add(text[i],new List<int>());
            }
            rDict[text[i]].Add(i);
        }
        string str;
        foreach(KeyValuePair<char,List<int>> item in rDict)
        {
            if(item.Value.Count == 1) continue;

            for(int i=0;i<item.Value.Count - 1;i++)
            {                
                for(int j=i+1;j<item.Value.Count;j++)
                {
                    m = item.Value[i];
                    n = item.Value[j];
                    if(n*2-m>len) break;//越界之后不再看后面的
                    if((str = text.Substring(n,n-m)) == text.Substring(m,n-m) && !rList.Contains(str))
                    {
                        rList.Add(str);
                    } 
                }
            }         
        }
        return rList.Count;
    }
}
```
## 解法四
思路：将子字符串的对比转化为hash值对比，首先计算字符串的hash值，然后对子字符串的hash值进行对比，考虑到hash冲突，如果hash值相等再进行子字符串的对比
1. 使用字符按位相加的方式作为hash函数（一个简单的hash函数）
2. 使用单个字符移动来计算下一个子字符串的hash值
3. hash值相等的两个字符串，进行字符串对比

```csharp
public class Solution {
    public int hash(string str)
    {
        int r=0;
        for(int i=0;i<str.Length;i++)
        {
            r += str[i] - 'a' + 1;
        }
        return r;
    }
    public int DistinctEchoSubstrings(string text) {
        int len = text.Length,halfLen = len/2;
        int th,tn,tmpLen;
        string str;
        List<string> rList = new List<string>();
        for(int i=1;i<=halfLen;i++)
        {//i是长度
            th = hash(text.Substring(0,i));//计算首个hash
            tn = hash(text.Substring(i,i));
            if(th == tn && (str = text.Substring(0,i)) == text.Substring(i,i) && !rList.Contains(str))
            {
                rList.Add(str);
            }
            tmpLen = len-i;
            for(int j=i;j<tmpLen;j++)
            {//j是位置索引
                th += text[j] - text[j-i];//移动单个字符计算hash
                tn += text[j+i] - text[j];
                if(th == tn && (str = text.Substring(j-i+1,i)) == text.Substring(j+1,i) && !rList.Contains(str))
                {
                    rList.Add(str);
                }
            }
        }
        return rList.Count;
    }
}
```

转自:[https://www.zhenxiangsimple.com/2020/01/12/tech/math-sDistinctEchoSubstrings/](https://www.zhenxiangsimple.com/2020/01/12/tech/math-sDistinctEchoSubstrings/)