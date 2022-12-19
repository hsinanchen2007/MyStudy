## 解法一（有序字典）
思路：使用字典存储有序列表便于顺序查找，查询主要是在指定的区间内对数据计数。方案比较简洁，难点审题和调试。
测试用例容易晕，调试时候遇到较长的测试用例及对应的预期输出如下，自己用了1个多小时通过测试用例，找输出对应的输入，用了1秒解决了问题：
1. 插入数据时，生成有序字典，也可以改用二分法加快效率
2. 使用起止时间差作为结束条件，每一个对应的时间间隔输出计数的插入数据

* 时间复杂度：O(n)
* 空间复杂度：O(n)


* 测试用例：[https://www.zhenxiangsimple.com/files/tech/testCase20200209.txt](https://www.zhenxiangsimple.com/files/tech/testCase20200209.txt)
* 预期输出：[https://www.zhenxiangsimple.com/files/tech/testCase20200209-1.txt](https://www.zhenxiangsimple.com/files/tech/testCase20200209-1.txt)
```csharp
public class TweetCounts {
    
    Dictionary<string,List<int>> list;

    public TweetCounts() {
        list = new Dictionary<string,List<int>>();
    }
    
    public void RecordTweet(string tweetName, int time) {
        if(!list.ContainsKey(tweetName))
        {//新名字
            list.Add(tweetName,new List<int>());
        }
        List<int> r = list[tweetName];
        int i=0;
        for(;i<r.Count;i++)
        {//按从小到大，找到插入位置
            if(r[i] >= time)
            {
                break;
            }
        }
        r.Insert(i,time);
    }
    
    public IList<int> GetTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int unit = 0;
        switch(freq)
        {
            case "hour":unit=3600;break;
            case "day":unit=24*3600;break;
            default:unit=60;break;                
        }
        if(!list.ContainsKey(tweetName))
            return null;
        List<int> r = list[tweetName];    
        List<int> t = new List<int>();
        int s=startTime,e=Math.Min(startTime+unit,endTime+1);
        int count =0 ,tmpCount = endTime - startTime;
        int idx = 0;
        while(idx<r.Count && r[idx] < s)
        {//跳过开始前的数据
            idx++;
        }
        while(tmpCount >= 0)
        {
            count = 0;
            for(int i=idx;i<r.Count;i++)
            {
                if(r[i] >= s && r[i] < e) 
                {//对区间数据计数
                    count++;
                    idx++;
                }
            }
            tmpCount -= unit;
            s=e;
            e=Math.Min(s+unit,endTime+1);
            t.Add(count);
        }
        return t;
    }
}
```
***
## 解法二