### 解题思路
java，0往前放，2往后放

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
		int q = nums.length-1;		//指向已经调整好的数2
		int p = 0;					//指向已经调整好的数0
		int i = 0;

		while(i<=q && p<=q){
			if(nums[p]==0){
				p++;
				continue;
			}
			if(nums[q]==2){
				q--;
				continue;
			}
			if(i<p){
				i++;
				continue;
			}
			if(i>q){
                break;
            }

			if(nums[i]==0){
				nums[i] = 1;
				nums[p] = 0;
				p++;
			}

			if(nums[i]==2){
				if(nums[q]==0){
					nums[i] = 1;
					nums[p] = 0;
					p++;
					nums[q] = 2;
					q--;
				}else{
					nums[i] = 1;
					nums[q] = 2;
					q--;
				}
			}
			i++;

		}
    }
}
```