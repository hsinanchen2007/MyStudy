```
import java.util.ArrayList;

public class MyCalendarTwo {
    class Pair{
        Integer first, second;        
        Pair(int _f, int _s) {
            first = _f; second = _s;
        }
    }
    private ArrayList<Pair> firsts = new ArrayList<>();     //出现过一次的区间
    private ArrayList<Pair> seconds = new ArrayList<>();    //出现过两次的区间

    public boolean book(int start, int end) {
        for (Pair pair: seconds) {
            if (!(pair.first >= end || pair.second <= start)) {  //出现三次就返回false
                return false;
            }
        }
        for (Pair pair: firsts) {
            if (!(pair.first >= end || pair.second <= start)) {
                //加入(max(first1, first2), min(second1, second2))作为出现过两次
                seconds.add(new Pair(pair.first > start ? pair.first : start, pair.second < end ? pair.second : end));
            }
        }
        firsts.add(new Pair(start, end)); //出现过一次
        return true;
    }
}

```

