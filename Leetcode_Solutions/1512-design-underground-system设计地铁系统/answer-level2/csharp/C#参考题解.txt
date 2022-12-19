我在比赛的时候写了两个类
一个Passager类，还有一个PassagerInfo类
Passager类用于创建乘客对象
PassagerInfo类里创建了一个Passager List，以及求平均时间的静态方法
后来执行出错，我用对比文档看了一下，是有几个checkout的小数有一些问题，我现在猜测可能是同步异步导致的数据问题？没有得到求证。
现在我优化了一下自己的代码，就写一个PassagerInfo类，UndergroundSystem类里创建两个PassagerInfo的List（PassagersIn用于管理在站内的乘客信息，PassagersOut用于管理已出站的乘客信息），具体代码如下
```
public class PassagerInfo
{
	public int id;
	public string startStation;
	public string endStation;
	public int startTime;
	public int endTime;


	public PassagerInfo(int id, string startStation, int startTime)
	{
		this.id = id;
		this.startStation = startStation;
		this.startTime = startTime;
	}


}
    public class UndergroundSystem
    {
        List<PassagerInfo> passagersIn;
        List<PassagerInfo> passagersOut;

        public UndergroundSystem()
        {
            passagersIn = new List<PassagerInfo>();
            passagersOut = new List<PassagerInfo>();
        }

        public void CheckIn(int id, string stationName, int t)
        {
            passagersIn.Add(new PassagerInfo(id, stationName, t));
        }

        public void CheckOut(int id, string stationName, int t)
        {
            for (int index = 0; index < passagersIn.Count; index++)
            {
                PassagerInfo curInfo = passagersIn[index];
                if(curInfo.id==id)
                {
                    curInfo.endStation = stationName;
                    curInfo.endTime = t;
                    passagersOut.Add(curInfo);
                    passagersIn.Remove(curInfo);
                }
            }
        }

        public double GetAverageTime(string startStation, string endStation)
        {
            double totalTime = 0;
            double count = 0;
            foreach (var passager in passagersOut)
            {
                if (passager.startStation == startStation && passager.endStation == endStation)
                {
                    count++;
                    totalTime += passager.endTime - passager.startTime;
                }
            }
            return totalTime / count;
        }


    }
```

