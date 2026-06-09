**思路：总共需要待机的时间+任务总数量**
* 任务数量多的任务执行的优先级最高，任务数量相同的则等待时间长的优先级高
* 以任务数量最多(max)的任务为基准分成若干个执行模块，模块数量(partCount)为max - 1
* 在模块内任务的安排原则与前面一样，若又maxCount种有max个的任务，
   则在模块初始化时要将它们全部都考虑进去
* 再算每个模块内还余留的空闲位置(partLen)，partLen =  n - (maxCount - 1)，减一是减去最初的分化模块的基准任务
* 则可以得到所有模块中余留的空位(emptySlots) 为partCount * partLeft
* 而剩下的需要进行调度的任务(taskLeft)是原数组中分化模块后剩下的所有任务，为tasks.length - (max * maxCount)
* 比较emptySlots与taskLeft的长度，得到需要待机的时间(idles)，为max(0, emptySlots - taskLeft)
* 由上可知结果即为tasks.length + idles

```
class Solution {
    public int leastInterval(char[] tasks, int n) {
        //max表示出现认为最多次次数，
        //maxCount表示同时出现max次的不同认为个数
        int max = 0, maxCount = 0;
        //cnt数组在相应位置储存不同任务出现的次数
        int[] cnt = new int[26];
        
        for(char task : tasks){
            cnt[task - 'A']++;
            if(max == cnt[task - 'A'])
                maxCount++;
            else if(max < cnt[task - 'A']){
                max = cnt[task - 'A'];
                maxCount = 1;
            }
        }
        //模块数
        int partCount = max - 1;
        //模块的长度
        int partLen = n - (maxCount - 1);
        //模块中的总空位置数量
        int emptySlots = partCount * partLen;
        //剩余的任务数量
        int taskLeft = tasks.length - max * maxCount;
        //要休息的时间总数，多余的空位数即是要休息的时间
        int idles = Math.max(0, emptySlots - taskLeft);
        
        return tasks.length + idles;
    }
}
```