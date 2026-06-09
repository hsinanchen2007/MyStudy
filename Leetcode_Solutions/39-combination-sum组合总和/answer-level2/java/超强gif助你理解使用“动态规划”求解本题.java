# 前言
看这题的题解，大家都是用`回溯法`解的。随着我把组合总和的[II](https://leetcode-cn.com/problems/combination-sum-ii/)、[III](https://leetcode-cn.com/problems/combination-sum-iii/)、[IV](https://leetcode-cn.com/problems/combination-sum-iv/)做完，尤其是到IV的时候，回溯算法就超时了，而IV恰好是用动态规划解决的，于是我就思考：能不能用`动态规划`求解本题。

# 主要思想
对于目标值target，它一定是由比它小的数相加得到的。比如5=1+4=2+3，而4=3+1=2+2，3=2+1，2=1+1...，也就是说，从1开始，我们依次求解每个数可以有几种形成的方式，则数值更高的数的组合方式建立在数值低的数的组合方式上得到，好吧我自己都没看懂我说的话，直接看图片吧。


## 准备工作
初始化一个数组`dict`，键是1~target，值初始化为空列表。

## 分析`1`的组成方式
![1.gif](https://pic.leetcode-cn.com/aa56c93c2dbafb2e3762ad87fba7a2e43e891c7e3b77b07f77b536a5ed112c43-1.gif)


##### 得到：`1`只可以由[1]这1种方式组成。

## 分析`2`的组成方式
![2.gif](https://pic.leetcode-cn.com/e935252d2edcccb56a2bb07dd5e4d4720915947d0f25c49b36a8c40699ff1a75-2.gif)



##### 得到：`2`只可以由[1,1],[2]这2种方式组成。
## 分析`3`的组成方式
![3.gif](https://pic.leetcode-cn.com/5e9d47666166af237caf5216760c6e54b3bc58ceca660f97c72f4571991fafb5-3.gif)


##### 得到：`3`可以由[1,1,1],[1,2],[3]这3种方式组成。
## 分析`4`的组成方式
（其中有两次的来回动画，帮助你理解拿取的是哪一个）
![4.gif](https://pic.leetcode-cn.com/72488722ef5f7d41aab5083b86a9c663f3b97b3085cd5b53d40020c85480d29a-4.gif)


##### 得到：`4`可以由[1,1,1,1],[1,1,2],[2,2],[3,1],[4]这5种方式组成。
## 分析`5`的组成方式
（抱歉来回了3次，我觉得`来回来回`好魔性啊~哈哈哈！！）
![5.gif](https://pic.leetcode-cn.com/ed4f041592003fc654099ea3ad89e7c6debba3eceea7722d1dd5ff80145a18cc-5.gif)



##### 得到：`5`可以由[1,1,1,1,1],[1,1,1,2],[2,2,1],[3,1,1],[3,2],[4,1]这6种方式组成。


# 总结
求解一个值，需要求解上一个值，进而需要求解上上个值...，这种方法就是动态规划。重复的值只需要进行一次，而后再使用到这个值时，只需要将他的结果拿来适当增加即可。

# 感谢
受编程水平限制，博主最初只提供了Python3的代码，欢迎其他编程语言爱好者提供相应代码复现`动态规划`。

C++版本1算法由[@lan-yun-2](/u/lan-yun-2)提供。

C++版本2算法由[@pris_bupt](/u/pris_bupt)提供。

Java算法由[@liu-li-8](/u/liu-li-8)提供。
```python []
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        dict = {}
        for i in range(1,target+1):
            dict[i]=[]
        
        for i in range(1,target+1):
            for j in candidates:
                if i==j:
                    dict[i].append([i])
                elif i>j:
                    for k in dict[i-j]:
                        x = k[:]
                        x.append(j)
                        x.sort() # 升序，便于后续去重
                        if x not in dict[i]:
                            dict[i].append(x)

        return dict[target]
```
```c++ []
// 由@lan-yun-2提供
map<int, set<vector<int> > > dpkv;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int> > avectorset;
        // 初始化
        for(int i = 1; i <= target; i++){
            dpkv[i] = avectorset; // 都赋值成一个空的数组
        }
        // 开始递推
        
        for(int j = 1; j <= target; j++){
            for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++){
                if(j == *it){
                    // 直接作为一个vector<int>加入
                    vector<int> v_only_one_num;
                    v_only_one_num.push_back(j);
                    dpkv[j].insert(v_only_one_num);
                } else if(j > *it){ // 用dp[j - *it] 作为结果
                    // 遍历dp[j - *it]
                    for(set<vector<int> >::iterator its = dpkv[j - *it].begin(); its != dpkv[j - *it].end(); its++){
                        vector<int> the_vector = (*its);
                        the_vector.push_back(*it);
                        sort(the_vector.begin(), the_vector.end());
                        dpkv[j].insert(the_vector);
                    }
                }
            }
        }
        // 将set加工成vector
        vector<vector<int>> target_v;
        for(set<vector<int> >::iterator its = dpkv[target].begin(); its != dpkv[target].end(); its++){
            target_v.push_back(*its);
        }
            
        return target_v;
    }
};
```
```c++ []
// 由@pris_bupt提供
 vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	unordered_map<int, set<vector<int>>>dict;
	for (int i = 1; i <= target; i++)
	    for (int it : candidates) 
		if (i == it) dict[i].insert(vector<int>{it});
		else if (i > it)
		     for (auto ivec : dict[i - it]) {
			ivec.push_back(it);
			sort(ivec.begin(), ivec.end());
			if(dict[i].count(ivec)==0)
		            dict[i].insert(ivec);
		    }
	vector<vector<int>>ans;
	for (auto it : dict[target]) ans.push_back(it);
	return ans;
}
```
```java []
// 由@liu-li-8提供
class Solution {
  public List<List<Integer>> combinationSum(int[] candidates, int target) {
      List<List<Integer>> result = new ArrayList<>();
      Map<Integer,Set<List<Integer>>> map = new HashMap<>();
      //对candidates数组进行排序
      Arrays.sort(candidates);
      int len = candidates.length;
      for(int i = 1;i <= target;i++){
          //初始化map
          map.put(i,new HashSet<>());
          //对candidates数组进行循环
          for(int j = 0;j < len&&candidates[j] <= target;j++){
              if(i == candidates[j]){
                  //相等即为相减为0的情况，直接加入set集合即可
                  List<Integer> temp = new ArrayList<>();
                  temp.add(i);
                  map.get(i).add(temp);
              }else if(i > candidates[j]){
                  //i-candidates[j]是map的key
                  int key = i-candidates[j];
                  //使用迭代器对对应key的set集合进行遍历
                  //如果candidates数组不包含这个key值，对应的set集合会为空，故这里不需要做单独判断
                  for(Iterator iterator = map.get(key).iterator();iterator.hasNext();){
                      List list = (List) iterator.next();
                      //set集合里面的每一个list都要加入candidates[j]，然后放入到以i为key的集合中
                      List tempList = new ArrayList<>();
                      tempList.addAll(list);
                      tempList.add(candidates[j]);
                      //排序是为了通过set集合去重
                      Collections.sort(tempList);
                      map.get(i).add(tempList);
                  }
              }
          }
      }
      result.addAll(map.get(target));
      return result;
  }
}
```
# 总结
*`做题不是目的，目的是通过做题锻炼思维、掌握常用的算法。
——蠢萌哒小洋`*

不要做过了就忘了，要变成你自己的。

# 其他
如果有缘的话，大家也可以看到我在[其他一些题目下面写的题解](https://leetcode-cn.com/profile/articles/)，同样都是以`超强gif助你理解使用...`开头的，我坚信**能用图说明白的绝不用嘴BB**，而且图片更直观形象，动画能更好的反应程序是怎么执行的、某个变量如何获取、它下一步到哪去了等等。做gif还是挺耗时间和精力的，所以大家要是喜欢的话记得点赞或者关注，当然**有什么建议也可以评论**，我会听的！才怪😜

有童鞋问我gif是怎么做的，我用的是**1.激活版** **2.PowerPoint365/其他*最新版*PowerPoint**，两个条件缺一不可。然后用Gif录制工具录下来的。




