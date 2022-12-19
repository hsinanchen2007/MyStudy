```
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        //可以的话设置两个值加进去
        List<Integer> numList = new ArrayList();
        int big = 0;//大汉堡(4,1)
        int small = 0;//小汉堡(2,1)
        if(tomatoSlices-2*cheeseSlices>=0){
            if(tomatoSlices%2!=0){
                return numList;
            }
            big = tomatoSlices/2-cheeseSlices;
            small = cheeseSlices-big;
            if(small<0){
                return numList;
            }
            numList.add(big);
            numList.add(small);
        }
        
//         while(tomatoSlices>4){
//             //4x y  z
//             //2x y
//             //4x+2y = tam 16, cheeseSlices = 
//             //x+y = che 7 2x = tam - 2*che
//         }
        
        
        // //判断tom大于等于四个开始进去筛选
        // if(tomatoSlices==0&&cheeseSlices==0){
        //     numList.add(0);
        //     numList.add(0);
        // }
        return numList;
    }
}
```
