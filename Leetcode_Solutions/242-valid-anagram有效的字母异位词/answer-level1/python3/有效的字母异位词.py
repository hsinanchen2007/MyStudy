###### 我的思路
`转成字典，看着两个字典是不是相同`
```
        a={key1:s.count(key1) for key1 in set(s)}
        b={key2:t.count(key2) for key2 in set(t)}
```
`这种方法比较快`
`另外直接使用sorted函数，效率低但代码简洁，就一行`
```
        sorted(s)==sorted(t)
```
