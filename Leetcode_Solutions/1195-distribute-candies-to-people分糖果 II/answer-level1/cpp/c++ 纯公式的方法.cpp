解题思路：主要涉及两个公式：（单这两个公式是用在当前轮所有人都分到应有的个数的糖的基础上的）
一.横向看，第一轮每个人分到的糖果数量为1,2,3,4,....n;(合计为$\frac{1}{2}n^2+\frac{1}{2}n)$第二轮的时候是$n+1,n+2,n+3,...n+n$;(第一第二轮合计为$\frac{4}{2}n^2+\frac{2}{2}n)$第三轮为$2n+1,2n+2,2n+3,2n+4,...2n+n$;(前三轮合计为$\frac{9}{2}n^2+\frac{3}{2}n$)。
所以假设第一轮为line=0,第二轮为line=1,...归纳得到前line轮糖果总和为\frac{n^2(line+1)^2+(line+1)n}{2}

二.竖向看，第一个小朋友，第一轮有1个，第二轮有n+1,第三轮2n+1;第二个小朋友，第一轮有2个，第二轮有n+2,第三轮2n+2; 所以每个小峰由前N轮手里糖的总和是$\frac{line(line+1)n+line+1+i+1}{2}$其中i表示当前小朋友排在队伍的第几个。

```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        //纯公式推导的方式计算      
        int line=-1,i,num;  //line初试为-1代表一排都没有分满，line等于0时代表分满了第一次      
        int res=candies;
        vector<int>  result(num_people,0);
        //计算得到完整分完几次一整排小朋友
        for( i=0;i<sqrt(candies);i++){
            // cout<<line<<endl; 
            if( (pow(num_people,2)*pow(line+1,2)+(line+1)*num_people )/2 <candies){
                line++;           
                }     
            else break;
        }
       
        line=line-1;
        // cout<<line;
        // 计算分了完整排后每个小朋友手里的糖的数量
        if(line>-1){
            for(i =0;i<num_people;i++ ){
                num=(i+1)*(line+1)+((line+1)*line*num_people)/2;
                // cout<<num<<endl;
                result[i]+=num;
            }
            res=candies-(pow(num_people,2)*pow(line+1,2)+(line+1)*num_people )/2;//表示剩余的糖果数量
        }
        // cout<<res<<endl;
        i=0;
        while(res){
            num=(line+1)*num_people+i+1;
            if(res>num){
                result[i]+=num;
                res-=num;
                i++;
            }else{
                result[i]+=res;
                res=0;i++;
            }
        }
        return result;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4a04e429cc5f8a61d359de03bff45b12e32e4fc7aeb5f01ce505e9cbb402532c-image.png)
