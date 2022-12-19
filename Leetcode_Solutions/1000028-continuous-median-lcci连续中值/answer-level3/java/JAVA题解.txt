### 解题思路
使用ArrayList保存输入的数字（可重复）
在findMedian方法中，先对ArryList列表中的数字进行排序，再判断总数，按奇偶两种情况返回中值。

### 代码

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class MedianFinder {

    private ArrayList<Integer> a = new ArrayList();


    /** initialize your data structure here. */
    public MedianFinder() {
        if (null == a) {
             a = new ArrayList<Integer>();
        }

    }

    public void addNum(int num) {
        a.add(num);
    }

    public double findMedian() {
        double result;
        int i = a.size();
        //排序
        Collections.sort(a);
        //判断奇偶数,如果是奇数，区中间数
        if (!isEven(a.size()))
        {
            result=(double) a.get(i/2);
        }
        else {
            result = ((double) (a.get(i/2)+ a.get(i/2-1))) / 2;
        }

    return result;
    }

    public boolean isEven(double num)
    {
        return num % 2 ==0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
```