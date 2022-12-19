```
class Solution {
    
    //注意点，新建全局变量 set形式，以便去重
    Set<List<Integer>> result=new HashSet<List<Integer>>();
    
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        //注意点，asList 方法的参数必须是对象或者对象数组，而原生数据类型不是对象
        List<Integer> calList=new ArrayList<Integer>();
        for (int item: candidates) {
            calList.add(Integer.valueOf(item));
        }
        int surplus=target;
        List<Integer> oneRes=new ArrayList<Integer>();
        calculate(calList,surplus,oneRes);
        //将set集合转为list集合输出
        return new ArrayList<List<Integer>>(result);
    
    }
    
    //注意点，入参需要有oneRes，这样后续递归时可以互相隔离，避免错乱
    private void calculate(List<Integer> calList,int surplus,List<Integer> oneRes) { 
        int len=calList.size();
        List<Integer> tempList=new ArrayList<Integer>();
        tempList.add(-1);
        tempList.addAll(calList);
        for(int i=0;i<len;i++){
            tempList.remove(0); //每次循环一次每次移除第一位索引元素
            //注意点，为了避免循环计算时，oneRes误累加，所以需要新建一个中间变量
            List<Integer> twoRes=new ArrayList<Integer>();
            twoRes.addAll(oneRes);
            int value=surplus-calList.get(i);
            if(value<calList.get(0) && value!=0){ //代表surplus是叶结点，这个分支不符合条件
                continue;
            }else if(value==0){ //代表surplus是叶结点，这个分支符合条件
                twoRes.add(calList.get(i));
                //list转数组，然后排序，再转为list
                Integer[] twoArr = new Integer[twoRes.size()];
                twoRes.toArray(twoArr);
                Arrays.sort(twoArr);
                twoRes=Arrays.asList(twoArr);
                result.add(twoRes);
            }else if(value>=calList.get(0)){  //代表value不是叶结点
                twoRes.add(calList.get(i));
                calculate(tempList,value,twoRes);
            }
                
        }
    }
        
}
```
