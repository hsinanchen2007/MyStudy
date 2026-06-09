![图片.png](https://pic.leetcode-cn.com/b048c4425f8bc994289e9b96aca4fe6b2f377b991d7500c300ccb4a09b4719d6-%E5%9B%BE%E7%89%87.png)
如果为题目中的所示例子的时候
![图片.png](https://pic.leetcode-cn.com/d187e28bc49704be1773bb5594f2c2eb077c349fadc1fdf3d9c4e076eb72a78d-%E5%9B%BE%E7%89%87.png)
打头的相当于4，减去左边的两块B之后值变为2，相等于求出idle_slots的
值为2，tasks.size()为前面的6块，所以总共的面积为6+2 = 8块面积
如果正好可以放入的时候
![图片.png](https://pic.leetcode-cn.com/d58e3dfc31d6c8f465cf79a325cfc58714c1d69f67d6da339d22b5f79de4af88-%E5%9B%BE%E7%89%87.png)
此时右上角的2*2 = 4，已经可以超出相应的区域了，所以选择tasks.size()即可
![图片.png](https://pic.leetcode-cn.com/a608ab4a72aa2b6449944dbdd68b3b3a51f7cbafdbbee3a555aff22e74dadcbb-%E5%9B%BE%E7%89%87.png)
从图中可以看出右上角的2*2 = 4的区域已经被填满了，所以此时选择tasks.size()
归根结底就是在没有将那块区域填满的时候(有空白的时候)选择那块区域的大小
在将那块区域填满的时候选择超出那块区域的大小
max(那块区域，右上角的总块数)

