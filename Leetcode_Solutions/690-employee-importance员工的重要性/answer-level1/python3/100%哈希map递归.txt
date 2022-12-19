![image.png](https://pic.leetcode-cn.com/34f02f32206b5563e71e0b11d47e4db4c8dca586d925ce9a93847917e20246f2-image.png)

时间还行，就是空间有点差。

其实就是理解题意，employees是指针数组，需要遍历一次employees把employees的importance和subordinates，按照id号存进字典，然后递归求和。

这里递归函数是把自己的本身重要值和各个下属部门的重要值，如果下属部门是空的，那自然就是只有自己的重要值了，所以递归函数只用写一行就行了。

存进数组再求和似乎更快更稳定一些，此处[* ]相当于list()。

```
class Solution:
    def getImportance(self, employees, id):
        di,ds={},{}
        for c in employees:
            di[c.id]=c.importance
            ds[c.id]=c.subordinates
        def f(i):
            return sum([di[i]]+[*map(f,ds[i])])
        return f(id)
```

更简单的写法，就是直接把employees的指针记进字典，速度差不多，但好像没有上面的写法快,不管存不存进数组,反正最快纪录是上面这个代码创造：

```
class Solution:
    def getImportance(self, employees, id):
        d={c.id:[c.importance,c.subordinates] for c in employees}
        def f(i):
            return sum([d[i][0]]+[*map(f,d[i][1])])
        return f(id)
```


```
class Solution:
    def getImportance(self, employees, id):
        d={c.id:c for c in employees}
        def f(i):
            return d[i].importance+sum(map(f,d[i].subordinates))
        return f(id)
```
