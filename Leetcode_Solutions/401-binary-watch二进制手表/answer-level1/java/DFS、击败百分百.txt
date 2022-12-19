思路，点灯关灯， 如亮灯数量等于需求值， 进行判断，满足条件加到结果集，否则舍弃
```
class Solution 
{
    
    List<String> res = new ArrayList<String>();
    int[] watch = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
    int[] onOff = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    public List<String> readBinaryWatch(int num) 
    {
        if(num > 8) return res;
        dfs(num, 0, 0);
        return res;
    }
    
    public void dfs(int num, int onSum ,int start)
    {
        if(onSum == num)
        {
            addResult();
            return;
        }
        
        for(int i = start; i < watch.length; i++)
        {
            onOff[i] = 1;
            dfs(num, onSum + 1, i + 1);
            onOff[i] = 0;
        }
    }
    
    public void addResult()
    {
        int hour = 0;
        int minute = 0;
        for(int i = 0; i < onOff.length; i++)
        {
            if(onOff[i] == 1)
            {
                if(i < 4)
                {
                    hour += watch[i];    
                }   
                else
                {
                    minute += watch[i];
                }
            }
        }
        if(hour > 11 || minute > 59) return;
        String time = hour + ":" + ((minute < 10) ? "0"+minute : minute); 
        res.add(time);    
    }
}
```
