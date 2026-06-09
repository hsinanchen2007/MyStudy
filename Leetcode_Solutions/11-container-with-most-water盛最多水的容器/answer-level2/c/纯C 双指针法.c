```
int maxArea(int* height, int heightSize){
    int head = 0;
    int rear = heightSize - 1;
    int maxArea = 0;
    int tempArea = 0;

    while(head < rear)
    {
        tempArea = (rear - head) *                \
                   (height[head] > height[rear] ? \
                    height[rear] : height[head]);

        maxArea = (maxArea >= tempArea) ? maxArea : tempArea;

        if(height[head] >= height[rear])
        {
            rear--;
        }
        else
        {
            head++;
        }
    }

    return maxArea;
}
```
