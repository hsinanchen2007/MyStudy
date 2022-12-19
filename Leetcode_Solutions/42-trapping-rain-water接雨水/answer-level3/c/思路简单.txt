方法1：层层计数。以水的深度为层，递归计算每一层可以储存的水量。比如：0层为整个数组，一层为数组中第一个大于等于1的元素到最后一个大于等于1的元素组成的新数组。。。每层小于当前的深度的元素，代表可以积蓄1单位水。直到形成的新数组长度为0，递归结束。这是一个暴力直观的想法，但是第314个用力超时。
```
void findTrap(int* height,int heightSize,int* ret,int index){
    if(heightSize == 0){
        return;
    }
    int left = heightSize,right = 0;
    int *head = height;
    for(int i=0;i<heightSize;i++){
        if(height[i] < index){
            (*ret)++;
        }
        if(height[i] > index){
            left = i<left?i:left;
        }
        if(height[i] > index){
            right = i>right?i:right;
        }
    }
    if(left < right){
        head = head + left;
        findTrap(head,right-left+1,ret,index+1);
    }else{
        return;
    }
}
int trap(int* height, int heightSize){
    int ret =0;
    findTrap(height,heightSize,&ret,0);
    return ret;
}
```
方法2：自我感觉像上楼梯，其实就是双指针。观察图解，我们发现要积蓄雨水，需要形成一个谷地。左右两个指针分别指向谷地的两个谷峰，就可以计算谷中积蓄的雨水了。再更新左右指针，我们就可以像走楼梯台阶一样，找到最高的台阶，并算出数组开始到最高台阶之间积蓄的雨水量。同样思路，反向遍历数组最后到最高台阶，就可以计算出所有积蓄的雨水了。
```
int trap(int* height, int heightSize){
    int ret =0,i = 1;
    int left = 0,right = 0;
    for(;i<heightSize;i++){
        if(height[i] >= height[i-1]){
            left = i;
        }else{
            break;
        }
    }
    while(i<heightSize){
        for(;i<heightSize;i++){
            if(height[i] >= height[left]){
                right = i;
                i++; 
                break;
            }
        }
        if(left < right){
            int k = height[left]>height[right]?height[right]:height[left];
            for(int l=left;l<right;l++){
                if(height[l] < k){
                    ret += (k - height[l]);
                }
            }
            left = right;
        }else if(left == right){
        	break;
		}
    }
    i = left;
    int j = heightSize - 2;
    right = heightSize - 1;
    while(j>i){
    	if(height[j] >= height[j+1]){
            right = j;
            j--;
        }else{
            break;
        }
	}
	while(j>i){
        for(;j>=i;j--){
            if(height[j] >= height[right]){
                left = j;
                j--; 
                break;
            }
        }
        if(left < right){
            int k = height[left]>height[right]?height[right]:height[left];
            for(int l=left;l<right;l++){
                if(height[l] < k){
                    ret += (k - height[l]);
                }
            }
            right = left;
        }else if(left == right){
        	break;
		}
    }
    return ret;
}
```
