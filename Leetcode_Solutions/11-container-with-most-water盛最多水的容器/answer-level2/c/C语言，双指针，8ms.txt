
![c.JPG](https://pic.leetcode-cn.com/78c5ba63c94201616e0aa9c41b781e7e2b1637e1f0c357c33fa2a294b4ca97ad-c.JPG)

```
int min(int a,int b){
    return (a<b)?a:b;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int maxValue = 0;

    while(left!=right){                
        maxValue = max(maxValue,(min(height[left],height[right]) * (right-left)));
        if (height[left]<height[right]){
            left++;            
        }
        else{
            right--;
        }
    }
    return maxValue;        
}
```


