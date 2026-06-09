
字典枚举法，分别统计0-12和0-60中每个数字二进制1的个数，然后单次遍历手表第一行0-4即可根据字典得出全部结果，
时间复杂度O（NlogN）

执行用时 :344 ms, 在所有 C# 提交中击败了100%的用户
内存消耗 :29.6 MB, 在所有 C# 提交中击败了16.67%的用户

```c# []
public IList<string> ReadBinaryWatch(int num) {
        var dictA=new Dictionary<int,List<int>>();
        var res=new List<string>();
        for(var i=0;i<12;i++){
            var t=BitCount(i);
            if(dictA.ContainsKey(t)){
                dictA[t].Add(i);
            }else{
                dictA[t]=new List<int>{i};
            }
        }
          
        var dictB=new Dictionary<int,List<int>>();
        for(var i=0;i<60;i++){
            var t=BitCount(i);
            if(dictB.ContainsKey(t)){
                dictB[t].Add(i);
            }else{
                dictB[t]=new List<int>{i};
            }
        }
        for(var i=0;i<=4&&dictA.ContainsKey(i);i++){
            var j=num-i;
            if(j>=0&&dictB.ContainsKey(j)){
                foreach(var a in dictA[i]){
                    foreach(var b in dictB[j]){
                        if(b<10){
                            res.Add($"{a}:0{b}");
                        }else{
                            res.Add($"{a}:{b}");
                        }
                    }
                }
                
            }
        }
        return res;
    }
    
    int BitCount(int n){
        var count=0;
        while(n>0){
            n&=(n-1);
            count++;
        }
        return count;
    }
```




暴力穷举法：

逻辑简单，时间复杂度为O（N^2）

```python []
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        list=[]
        for i in range(12):
            for j in range(60):
                if self.bitCount(i)+self.bitCount(j)==num:
                    list.append("%d:%02d"%(i, j))
        return list
        
    def bitCount(self,num:int)->int:
        count=0
        while num>0:
            num=num&(num-1)
            count+=1
        return count
```

