### 解题思路
模仿官方题解代码，用队列维持在3000 以内的数，超过的话就直接删除
### 代码

```csharp
public class RecentCounter{
    public Queue<int> pings;
    public RecentCounter(){
        pings = new Queue<int>();
    }
    public int Ping(int t){
        pings.Enqueue(t);
        while(pings.Peek()<t-3000){
            pings.Dequeue();
        }
        return pings.Count;
    }
}
// public class RecentCounter {
//     public List<int> pings = new List<int>();
   
//     public RecentCounter() {
        
//     }
    
//     public int Ping(int t) {
//         pings.Add(t);
//         if(pings.Count==0) return 0;
//         int res = 1;
//         int start = pings[pings.Count-1];
//         for(int i = pings.Count-2;i>-1;i--){
//             if(pings[i]>=start-3000) res++;
//             else break;
//         }   
//         return res;
//     }
// }

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.Ping(t);
 */
```