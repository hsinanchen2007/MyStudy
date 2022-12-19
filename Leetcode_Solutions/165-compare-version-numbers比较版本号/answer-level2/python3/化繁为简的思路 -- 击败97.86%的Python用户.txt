### 解题思路
0、乍一看，这道题目需要考虑的东西太多了。但是用化繁为简的思维模式，一步一步分析，你会发现，其实很简单。
1、根据题目的意思可知，这是一道简单的比对问题。
2、判断版本号大小，其实是判断同级别每个点号之间的数据的大小问题
3、所以，我们可以用两个list分别存储两个版本的每个点号之间的数据
4、因为不同的版本号可能位数不同，例如，1.0与1.1.2，这种情况就需要把版本补齐，即前者添加0,
5、最后，再比对两个list中的数据大小即可。

### 代码

```python3
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        list1 = []
        list2 = []
        value1 = 0
        value2 = 0

        for cnt1 in range (len(version1)):
            if version1[cnt1] != '.':
                value1 = (value1 * 10) + int(version1[cnt1])
            else:
                list1.append(value1)
                value1 = 0
            # 把最后一个点之后的数据加入到队列中
            if cnt1 == len(version1) - 1:
                list1.append(value1)

        for cnt2 in range (len(version2)):
            if version2[cnt2] != '.':
                value2 = (value2 * 10) + int(version2[cnt2])
            else:
                list2.append(value2)
                value2 = 0
            # 把最后一个点之后的数据加入到队列中
            if cnt2 == len(version2) - 1:
                list2.append(value2)
                
        # print(list1)
        # print(list2)
        
        num = Solution().ListCompare(list1, list2)

        return num


    def ListCompare(self, list1, list2):
        # 把两个list补齐，使之个数相同
        list1, list2 = Solution().MakeupList(list1, list2)

        # print(list1, list2)
        for cnt in range (len(list1)):
            if list1[cnt] > list2[cnt]:
                return 1
            elif list1[cnt] < list2[cnt]:
                return -1
            else:
                num = 0

        return num

    def MakeupList(self, list1, list2):
        if len(list1) > len(list2):
            cnt = len(list2)
            while cnt < len(list1):
                list2.append(0)
                cnt = cnt + 1
        else:
            cnt = len(list1)
            while cnt < len(list2):
                list1.append(0)
                cnt = cnt + 1

        return list1, list2
```