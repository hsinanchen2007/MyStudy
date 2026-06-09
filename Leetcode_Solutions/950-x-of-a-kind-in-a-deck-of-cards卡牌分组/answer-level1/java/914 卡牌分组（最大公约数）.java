### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int gcd(int a,int b){
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public boolean hasGroupsSizeX(int[] deck) {
        if(deck==null&&deck.length<2){
            return false;
        }
        int arr[]=new int[10000];
        for(int num:deck){
            arr[num]++;
        }
        int x = arr[deck[0]];
        for(int i=0;i<1000;i++){
            if(arr[i]==1){
                return false;
            }
            if(arr[i]>1){
                x=gcd(x,arr[i]);
                if(x==1){
                    return false;
                }
                
            }
        }
         return true;
       
    }
}
    //     if(deck==null&&deck.length==0){
    //         return false;
    //     }
    //     boolean a=true;
    //     Map<Integer,Integer> map=new HashMap<>();
    //     for(int i=0;i<deck.length;i++){
    //         if(map.containsKey(deck[i])){
    //             int temp=map.get(deck[i]);
    //             temp+=1;
    //             map.put(deck[i],temp);

    //         }else{
    //             map.put(deck[i],1);
    //         }
    //     }
    //     int constant=0;
    //     for(int pai:map.keySet()){
    //         int count=map.get(pai);
    //         if(count<2){
    //             a=false;
    //             break;
    //         }else if(constant==0){
    //             constant=count;
    //             // System.out.println(count+"a");
    //         }else if(constant!=0){
    //             int temp=map.get(pai);
    //             // System.out.println(temp+"b");
    //             int max=Math.max(constant,temp);
    //             int min=Math.min(constant,temp);
    //             // System.out.println(temp+"b");
    //             System.out.println(max+"max");
    //             System.out.println(min+"min");
    //             if(max/min==0||(max/min>0&&max%min!=0)){
    //                 System.out.println(max+"a");
    //                 System.out.println(min+"a");
    //                 a=false;
    //                 break;
    //             }
    //         }

    //         // System.out.println(count);
    //     }

    //     return a;
    // }
```