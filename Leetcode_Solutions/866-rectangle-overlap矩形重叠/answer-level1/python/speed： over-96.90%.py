
![image.png](https://pic.leetcode-cn.com/1ee40692beb6b52b76b3128a5a3a1cbbd517b5c7a79974829b81aff649e4ccc4-image.png)

### 我们先把第一个矩形看做固定的，然后分两步（这两部没有先后顺序）
1. 确定第二个矩形的左下角取值范围
2. 确定第二个矩形的右上角取值范围
# 
### 1、确定第二个矩形的左下角取值范围
拿第二个矩形来靠，看什么情况下才有可能相交。
通过下面的图，很显然，**只有第二个矩形的左下角坐标要小于第一个矩形右上角坐标时才有可能相交**
![image.png](https://pic.leetcode-cn.com/4c8d7b92c748bb74846e22677644da3c5313529de21bd996711e4dfd264f1c63-image.png)

# 
### 2、确定第二个矩形的右上角取值范围
上面这一步只是确定可能相交，即使满足上面的条件也有可能不想交，比如上图中左下角这个rec2就不想交。所以，我们还需要**确定第二个矩形的右上角取值范围**，如下图：
![image.png](https://pic.leetcode-cn.com/46830e3d083bb083d4a0885e74c2150922e9d14b636b8e0ce379e0a9e65b62d4-image.png)
可以看到，**只有第二个矩形的右上角坐标要大于第一个矩形的左下角下标**，才有可能相交（也就是图中绿色的），这样就把第一张图中左下角的那个矩形过滤掉了。

# 
### 有了思想后，写代码就很方便了。一行代码直接return
```python
def is_rectlang_overlap(rec1, rec2):
    return rec2[0] < rec1[2] \
           and rec2[1] < rec1[3] \
           and rec2[2] > rec1[0] \
           and rec2[3] > rec1[1]
```
