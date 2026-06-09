本题我采用了 两种方法。第一种方法是借鉴了有向图的入度数目判别，第二种方法其实和方法一差不多，步骤上精简些。
**方法一：有向图的入度数目判别法**
用一个字典用来记录每个节点的入度，对应条件二，即所有人得相信法官。那么，法官节点对应的入度应为N-1；用一个集合记录会信任他人的一群人，对应条件一，即法官不能相信任何人，那么法官不能在该集合中。
代码如下：
```Python
class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        if not trust:
            return N
        # 该集合记录会信任他人的一群人，对应条件一，即法官不能相信任何人
        tmp = []
        # 该字典用来记录每个节点的入度，对应条件二，即所有人得相信法官。
        # 那么，法官节点对应的入度应为N-1
        trust_dict = {}
        for node in trust:
            tmp.append(node[0])
            if node[1] not in trust_dict:
                trust_dict[node[1]] = 1
            else:
                trust_dict[node[1]] += 1
        # 遍历tmp列表判断条件一是否成立，遍历trust_dict字典判断条件二是否成立
        for people in trust_dict:
            if people not in tmp and trust_dict[people] == N-1:
                return people
        return -1


if __name__ == "__main__":
    N = 3
    trust = [[1,3],[2,3],[3,1]]
    print(Solution().findJudge(N, trust))
```
运行效率属于中等吧，在54%左右。

**方法二：**
其实和方法一比较类似，只是方法一有两次遍历，方法二只有一次遍历。方法二也是首先创建一个字典trust_dict来记录图的边集合，key值表示信任别人的人，value值列表集合表示当前people信任的一群人，其实可以理解为图中所有有向无权边的集合。
那么如何检查出法官呢？
两个条件：1）法官不在图字典trust_dict的key值集合中；2）法官在其余每个key值对应的value值中。
当然这其中还包含了一种特殊情况，就是给定的trust列表集合没有给全N个人的信任关系，所以得再一些判断，具体可见代码。
代码如下：
```Python
class Solution(object):
    def findJudge(self, N, trust):
        """
        :type N: int
        :type trust: List[List[int]]
        :rtype: int
        """
        trust_dict = self.createGraph(trust)
        # 当前变量用来记录符合条件的法官
        Flag = -1
        # 遍历每一个人，检查是否符合法官的条件
        for people in range(1, N+1):
            # 如果有个people不在trust_dict字典对应的key值中，说明该people不信任任何人
            # 当然还有种情况就是该people不在trust列表中，即不信任任何人，也没有任何人信任他
            if people not in trust_dict:
                for key, value in trust_dict.items():
                    # 如果当前people没有被人信任，说明不是法官
                    if people not in value:
                        return -1
                # 此刻可能找到了符合法官条件的people，但还可能存在第二种情况，上面已解释
                Flag = people
        return Flag
    
    # 创建无权重的有向图，字典格式，其中value集合表示key值信任人的集合
    def createGraph(self, matrix):
        trust_dict = {}
        for trust in matrix:
            if trust[0] not in trust_dict:
                trust_dict[trust[0]] = []
            trust_dict[trust[0]].append(trust[1])
        return trust_dict


if __name__ == "__main__":
    N = 3
    trust = [[1,3],[2,3],[3,1]]
    print(Solution().findJudge(N, trust))

```
