```C# []
        /*
        * 题目概述：推文计数
        * 
        * 思路：类似桶排序的过程
        *   1.用 Hash 记录用户发推文的时间点
        *   2.知道 开始 和 结束 时间,以及频率,可以计算出来时间区间/频率,或者说桶的个数
        *       桶的个数 = (endtime - starttime) / freq + 1  
        *   3.拿到员工的推文时间点,然后依次往桶中放,桶只负责计数就好了
        *       当前的推文时间点属于哪个桶 = (timePoint - startTime) / freq
        *
        * 关键点：
        *
        * 题目已知,发推文的次数(n)和统计次数(m)的和是 10000,即 n + m = 10000
        * 时间复杂度：O(n * m)
        * 空间复杂度：O(10000)
        */
        public class TweetCounts
        {

            private IDictionary<string, IList<int>> m_personPoint;

            public TweetCounts() => m_personPoint = new Dictionary<string, IList<int>>();

            public void RecordTweet(string tweetName, int time)
            {
                if (!m_personPoint.ContainsKey(tweetName))
                    m_personPoint[tweetName] = new List<int>();

                m_personPoint[tweetName].Add(time);
            }

            public IList<int> GetTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
            {
                var freqCount = GetFreqCount(freq);
                var subCount = (endTime - startTime) / freqCount + 1;
                var forReturn = new int[subCount];

                IList<int> personPointList = new List<int>();
                if (m_personPoint.ContainsKey(tweetName))
                    personPointList = m_personPoint[tweetName];

                foreach (var pointItem in personPointList)
                {
                    if (pointItem < startTime || pointItem > endTime) continue;

                    forReturn[(pointItem - startTime) / freqCount]++;
                }

                return forReturn;
            }

            private int GetFreqCount(string freq)
            {
                var freqCount = 0;
                switch (freq)
                {
                    case "minute":
                        freqCount = 60;
                        break;

                    case "hour":
                        freqCount = 60 * 60;
                        break;

                    case "day":
                        freqCount = 60 * 60 * 24;
                        break;
                }

                return freqCount;
            }
        }
```
