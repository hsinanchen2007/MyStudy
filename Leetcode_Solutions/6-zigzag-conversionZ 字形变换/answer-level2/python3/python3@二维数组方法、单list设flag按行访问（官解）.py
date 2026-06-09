## 二维数组方法，很蠢的方法，即占空间也浪费时间
>写了一个小时，拍脑袋想出了用二维数组

太菜了哈哈，把这个代码放在这刺激自己。
```vim

def test3(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        part = numRows*2-2
        print(part)
        print(len(s))
        a = len(s)//part +1
        test = list(s)
        res = [["" for i in range((numRows-1)*a)] for i in range(numRows)]
        # for i in res:
        #     print(i)
        print("a",a)
        n =0
        for j in range((numRows-1)*a):
            # print(j)
            if n ==  numRows -1 or n == 0:
                n = 0
                for i in range(numRows):
                    if test != []:
                        # print("字符串",test)
                        res[i][j] = test[0]
                        # for i in res:
                        #     print(i)
                        test.remove(test[0])
                        # print(res)
                n += 1
            else:
                if test != []:
                    # print("转折")
                    # print((numRows-1)*a)
                    # print(test[0])
                    res[numRows-1-n][j] = test[0]
                    # print(res[n][j])
                    test.remove(test[0])
                n +=1
        # for i in res:
        #     print(i)
        ans = ""
        for i in res:
            # print(i)
            for j in i :
                if j !='':
                    ans += j
                    # print(ans)
        
        return ans
```
结果实在是太‘感动’了~~
羞羞脸~~

```yaml
Accepted
1158/1158 cases passed (1028 ms)
Your runtime beats 5.07 % of python3 submissions
Your memory usage beats 5.06 % of python3 submissions (19.9 MB)
```

## 单list按行访问存储，设置flag动态访问
>通过从左向右迭代字符串，我们可以定字符位于 Z 字形图案中的哪一行。

**解题思路**
和二维数组的思想区别在于，我们我们可以将二维数组的行list，改为用字符串来存储。
其实之后返回的值也是str所有用字符串可以更多地节省str-list-str的转换资源消耗

- 首先构建numRows行的list用来存储数据
    - 这里每一列都是一个字符串形式
- 假设 numRows为3，
    - 我们需要从res[0]到res[1]到2res[再]到1再res[0]到res[1]到res[2]的来存储字符串数据
这里我们需要定义flag，我们每访问完一次res[start]后：
- 如果此时的start为第一行或者最后一行
    - 则对flag取相反数，转换顺序
    - （我们开始 从0-1的访问时，可以先设置默认的flag为-1，当访问完res[0]后，取相反数，就是正方向了）
```python3 []
def test(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s
        res = ["" for i in range(numRows)]
        start, flag = 0, -1
        for c in s:
            # print(c)
            res[start] += c
            if start == 0 or start == numRows - 1: 
                flag = -flag
            start += flag
        # for i in range(numRows):
        #     print(res[i])
        return "".join(res)
```
bingo！
```
Accepted
1158/1158 cases passed (56 ms)
Your runtime beats 95.67 % of python3 submissions
Your memory usage beats 99.83 % of python3 submissions (12.7 MB)
```
[源码储存在github上，欢迎来提bug哦！-点击访问](https://github.com/Freen247/leetcode)
如果觉得不错请给我一个star谢谢了Stray_Camel(＾Ｕ＾)ノ~ＹＯ