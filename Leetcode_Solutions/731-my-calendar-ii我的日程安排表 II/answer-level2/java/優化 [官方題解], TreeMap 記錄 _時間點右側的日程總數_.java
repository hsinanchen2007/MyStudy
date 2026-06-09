### 解题思路

優化 [官方題解](https://leetcode-cn.com/problems/my-calendar-ii/solution/wo-de-ri-cheng-an-pai-biao-ii-by-leetcode/) 
在 官方題解 中使用 treeMap 記錄日程的異動數, 造成每一次 booking 時 要對全部的記錄作查找。
若將 treeMap 改成記錄 "時間點右側的日程總數", 則每一次 booking 時, 僅需對 start ~ end 內的記錄作修改即可。

### 代码

```java
class MyCalendarTwo {

    TreeMap<Integer,Integer> tm;//記錄時間點右側的日程總數
    public MyCalendarTwo() {
        tm=new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Integer prv=tm.floorKey(start);//取出開始時間點左側(含自身)的日程總數
        prv=prv==null?start:prv;//若無值則採用開始時間點
        while(prv!=null && prv<end){//比對開始時間點到結束時間點內是否有日程總數大於2,若有則回傳否
            int sum=tm.getOrDefault(prv,0);//取出檢查點的日程總數
            if(sum>=2) return false;//超過2,回傳否
            prv=tm.higherKey(prv);//取出下一個檢查點
        }
        prv=tm.floorKey(start);//取出開始點左側的鍵(含自身)
        int prvSum=prv==null?0:tm.get(prv);//取出開始點己有的日程總數
        Integer nxt=tm.floorKey(end);//取出結束點左側的鍵(含自身)
        int nxtSum=nxt==null?0:tm.get(nxt);//取出結束點己有的日程總數
        tm.put(start,prvSum+1);//設定開始點日程總數
        tm.put(end,nxtSum);//設定結束點日程總數
        //
        Integer iKy=tm.higherKey(start);//取出下一個檢查點
        while(iKy!=null&&iKy<end){//對開始點到結束點內的鍵, 都加一
            tm.put(iKy,tm.get(iKy)+1);//都加一
            iKy=tm.higherKey(iKy);//取出下一個檢查點
        }
        return true;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
```