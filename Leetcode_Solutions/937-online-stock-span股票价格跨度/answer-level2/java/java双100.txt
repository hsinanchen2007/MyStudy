![image.png](https://pic.leetcode-cn.com/20ddc97e4471c233a5836896a492a459a4a0a8ae95ac59a3ce7819186c96d164-image.png)

### 代码

```java

class StockSpanner {
    //辅助数组，存储每次next的答案
    int[] helper = new int[10000];
    //数据数组，存储每次next的price值
    int[] data = new int[10000];
    //当前data和helper的索引，初始化没数据所以为-1
    int currentIndex = -1;

    public StockSpanner() {

    }

    public int next(int price) {
        //临时索引指针
        int index = currentIndex;
        //返回值，helper当前索引下的值，默认为1；
        int h = 1;
        while (index >= 0 && price >= data[index]) {
            //如果index指针没有超出数组范围，并且price >= data[index]
            //代表着price的值不仅仅大于等于data[index]
            //它大于等于包括data[index]在内的共计helper[index]个值
            //所以用h=h+helper[index]
            h += helper[index];
            //既然确定data[index]在内的共计helper[index]个值符合要求
            //直接将index = index - helper[index]
            //此时data[index]的值不确定是否比price大，再次进行循环判断
            index = index - helper[index];
        }
        //currentIndex向后移，更新data和helper
        data[++currentIndex] = price;
        helper[currentIndex] = h;
        return h;
    }
}
```