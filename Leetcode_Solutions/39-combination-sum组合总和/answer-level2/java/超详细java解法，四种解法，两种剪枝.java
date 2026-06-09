#### 方法一
**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【思路】**
* candidates[]中的每一个数，都有取和不取两种状态
* 用`help(candidates,start+1,end,target,list,ans)`表示不取
* 用`help(candidates,start,end,target-candidates[start],list,ans)`表示取


**【代码】**
```java
public List<List<Integer>> combinationSum(int[] candidates, int target) {
    List<List<Integer>> ans=new ArrayList<>();
    help(candidates,0,candidates.length,target,new ArrayList<>(),ans);
    return ans;
}

void help(int[] candidates, int start, int end,int target,List<Integer> list,List<List<Integer>> ans){
    if(target==0){
        ans.add(new ArrayList<>(list));
        return;
    }
    if(start>=end || target<0)
        return;

    help(candidates,start+1,end,target,list,ans);
    list.add(candidates[start]);
    help(candidates,start,end,target-candidates[start],list,ans);
    list.remove(list.size()-1);
}
```
**【备注】**
* 可以用`target-candidates[start]>=0`的判断条件，做一定的**剪枝**

```java
public List<List<Integer>> combinationSum(int[] candidates, int target) {
     List<List<Integer>> ans=new ArrayList<>();
     help(candidates,0,candidates.length,target,new ArrayList<>(),ans);
     return ans;
 }

 void help(int[] candidates, int start, int end,int target,List<Integer> list,List<List<Integer>> ans){
     if(target==0){
         ans.add(new ArrayList<>(list));
         return;
     }
     if(start>=end || target<0)
         return;

     help(candidates,start+1,end,target,list,ans);
     if(target-candidates[start]>=0){
         list.add(candidates[start]);
         help(candidates,start,end,target-candidates[start],list,ans);
         list.remove(list.size()-1);
     } 
 }
```
* `ans.add(new ArrayList<>(list))`对于这一行代码有些读者可能有疑问，为什么不能直接`ans.add(list)`呢？这是一个传值和传引用的问题[【点此详见解析】](https://mp.weixin.qq.com/s?__biz=MzI4Njc4MzMwMw==&mid=2247483739&idx=1&sn=5274ec2e20d0dfde0d5ff80ea6e16933&chksm=ebd6e373dca16a657567a310ccd345cf72210aa6a17ac15cebbed7c1f4b903132ebdb16324bd&token=573689595&lang=zh_CN#rd)


#### 方法二

**【代码】**
```java
public List<List<Integer>> combinationSum(int[] candidates, int target) {
    List<List<Integer>> ans = new ArrayList<>();
    if(candidates==null) return ans;
    help(ans,new ArrayList<>(),0,target,candidates);
    return ans;
}
void help(List<List<Integer>> ans,List<Integer> cur,int start,int target,int[] candidates){
    if(target==0){
        ans.add(new ArrayList(cur));
        return;
    }else{
        for(int i=start ; i<candidates.length ; i++){
            if(target-candidates[i]>=0){
                cur.add(candidates[i]);
                help(ans,cur,i,target-candidates[i],candidates);
                cur.remove(cur.size()-1);
            }
        }
    }
}
```

**【备注】**
* 可以先对candidates[]排个序，这样可以做一些**剪枝**

```java
public List<List<Integer>> combinationSum(int[] candidates, int target) {
    Arrays.sort(candidates);
    List<List<Integer>> ans = new ArrayList<>();
    if(candidates==null) return ans;
    help(ans,new ArrayList<>(),0,target,candidates);
    return ans;
}
void help(List<List<Integer>> ans,List<Integer> cur,int start,int target,int[] candidates){
    if(target==0){
        ans.add(new ArrayList(cur));
        return;
    }
    if(target<0)
        return;
    for(int i=start ; i<candidates.length ; i++){
        if(target-candidates[i]>=0){
            cur.add(candidates[i]);
            help(ans,cur,i,target-candidates[i],candidates);
            cur.remove(cur.size()-1);
        }
        else
            break;
    }
}
```



* 关注我，带你拿大厂offer

![logo_gif.gif](https://pic.leetcode-cn.com/54ce78cdb83d29e79a256c7cb1c26389146c4c6ec46382d2bc317511aacd1722-logo_gif.gif)
