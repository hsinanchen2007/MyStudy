### 解题思路
因为之前做过三数和的题目，这道题终于不用看别人的题解了，不过效率不高，怕是有很多可以改进的地方，望指正

### 代码

```c
int compare(const void *value1, const void *value2) 
{
    return *(int*)value1 - *(int*)value2;
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);
	int p = 0; int q = numsSize - 1;
	int size = 0;
    if(numsSize<3||nums==NULL){
        return NULL;
    }
    int sum=nums[0]+nums[1]+nums[2];
	for (int i = 0; i <= numsSize - 2; i++) {
		if (i != 0 && nums[i - 1] == nums[i]){
			continue;
		}
		p = i + 1; q = numsSize - 1;
		while (p<q) {
			if (p != i + 1 && nums[p - 1] == nums[p]) {
				p++;
				continue;
			}
			if (q != (numsSize - 1) && nums[q] == nums[q + 1]) {
				q--;
				continue;
			}
			int threesum = nums[p] + nums[q] + nums[i];
			if ( abs(threesum - target) < abs(sum-target) ) {
				sum=threesum;
			}
            if(threesum-target>0){
                --q;
            }
            if(threesum-target<0){
                ++p;
            }
            
            if(threesum-target==0){
                break;
            }
		}
	}
	return sum;
}


```