
-   有序数组分割法

设置两个数组分别保存区间的起点与终点，这里采用的是闭区间

设置一个对应位置的数组，保存当前区间的覆盖次数



-   当拿到一个新的区间的时候，首先判断一下，是否有重叠区域
    -   不存在，直接插入新的区间，并插入覆盖次数1
    -   存在重叠

重叠区域与前面区间一共有下面几种：

1、重叠区间刚好能够覆盖前面相邻的区间

直接更新区间的覆盖值

```
+----------------------------------------------+
|                                              |
+----------------------------------------------+
|**********************************************|
|**********************************************|
|**********************************************|
|**********************************************|
|**********************************************|
+----------------------------------------------+
|                                              |
+----------------------------------------------+
```

2、重叠部分覆盖前面的左部

-   将原来区域切分成两部分

设原来区间的预订值为`book_num`

左部分的预定值为`book_num+1`

右部分的预定值为`book_num`

```
+----------------------------------------------+
|                                              |
+----------------------------+                 |
|****************************|                 |
|****************************|                 |
|****************************|                 |
|****************************|                 |
|****************************|                 |
+----------------------------+                 |
|                                              |
+----------------------------------------------+
```

3、重叠部分覆盖右部

-   将原来区域切分成两部分

设原来区间的预订值为`book_num`

左部分的预定值为`book_num`

右部分的预定值为`book_num+1`

```
+----------------------------------------------+
|                                              |
|                 +----------------------------+
|                 |****************************|
|                 |****************************|
|                 |****************************|
|                 |****************************|
|                 |****************************|
|                 +----------------------------+
|                                              |
+----------------------------------------------+
```

4、重叠部分覆盖中间一块区域

-   将原来的区间切分成左中右3部分

设原来区间的预订值为`book_num`

左部分的预定值为`book_num`

中部分的预定值为`book_num+1`

右部分的预定值为`book_num`

```
+----------------------------------------------+
|                                              |
|        +--------------------------+          |
|        |**************************|          |
|        |**************************|          |
|        |**************************|          |
|        |**************************|          |
|        |**************************|          |
|        +--------------------------+          |
|                                              |
+----------------------------------------------+
```



除此以外，考虑左右方超出范围的部分：

右方超出范围：

```
+----------------------------------------------+                      
|                                              |                      
|                                              +---------------------+
|                                              |*********************|
|                                              |*********************|
|                                              |*********************|
|                                              |*********************|
|                                              |*********************|
|                                              +---------------------+
|                                              |                      
+----------------------------------------------+                      
```

左方超出范围：

```
                      +----------------------------------------------+
                      |                                              |
+---------------------+                                              |
|*********************|                                              |
|*********************|                                              |
|*********************|                                              |
|*********************|                                              |
|*********************|                                              |
+---------------------+                                              |
                      |                                              |
                      +----------------------------------------------+
```



超出部分递归更新即可



代码实例：

```python
from bisect import bisect_right


class MyCalendarThree:

    def __init__(self):
        self.starts = []
        self.ends = []

        self.book_num = []
        self.max_book_num = 1

    def update(self, start, end):
        index = bisect_right(self.starts, end)
        if index == 0 or self.ends[index - 1] < start:
            self.starts.insert(index, start)
            self.ends.insert(index, end)
            self.book_num.insert(index, 1)
        else:
            pre_left, pre_right = self.starts[index - 1], self.ends[index - 1]
            overlap_left = max(start, pre_left)
            overlap_right = min(end, pre_right)

            current_book_num = self.book_num[index - 1]
            if overlap_left == pre_left and overlap_right == pre_right:
                self.book_num[index - 1] += 1
            elif overlap_left == pre_left and overlap_right < pre_right:
                # 分割两部分
                self.ends[index - 1] = overlap_right
                self.book_num[index - 1] += 1
                self.starts.insert(index, overlap_right + 1)
                self.ends.insert(index, pre_right)
                self.book_num.insert(index, current_book_num)

            elif overlap_right == pre_right and overlap_left > pre_left:
                # 分割两部分
                self.ends[index - 1] = overlap_left - 1
                self.starts.insert(index, overlap_left)
                self.ends.insert(index, pre_right)
                self.book_num.insert(index, current_book_num + 1)

            elif overlap_left > pre_left and overlap_right < pre_right:
                # 修改右侧部分
                self.starts[index - 1] = overlap_right + 1
                # 添加中间覆盖部分
                self.starts.insert(index - 1, overlap_left)
                self.ends.insert(index - 1, overlap_right)
                self.book_num.insert(index - 1, current_book_num + 1)
                # 添加左侧部分
                self.starts.insert(index - 1, pre_left)
                self.ends.insert(index - 1, overlap_left - 1)
                self.book_num.insert(index - 1, current_book_num)

            self.max_book_num = max(self.max_book_num, current_book_num + 1)

            if end > pre_right:
                self.update(pre_right + 1, end)
            if start < pre_left:
                self.update(start, pre_left - 1)

    def book(self, start: int, end: int) -> int:
        self.update(start, end - 1)
        return self.max_book_num

    # Your MyCalendarThree object will be instantiated and called as such:

# obj = MyCalendarThree()
# param_1 = obj.book(start,end)

```


