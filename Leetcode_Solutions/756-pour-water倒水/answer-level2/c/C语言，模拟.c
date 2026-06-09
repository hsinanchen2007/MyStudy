```

int* pourWater(int* heights, int heightsSize, int V, int K, int* returnSize)
{
    int *ans;
    int i, left, right, nowHeight, lowHeightPos;
    ans = (int*)malloc(sizeof(int) * heightsSize);
    
    while (V > 0) {
        V--;
        nowHeight = heights[K];
        lowHeightPos = K;
        left = K - 1;
        while (left >= 0) {
            if (heights[left] > nowHeight) {
                break;
            }
            if (heights[left] < nowHeight) {
                lowHeightPos = left;
                nowHeight = heights[left];
            }
            left--;
        }
        if (lowHeightPos < K) {
            heights[lowHeightPos]++;
            continue;
        }
        right = K + 1;
        nowHeight = heights[K];
        lowHeightPos = K;
        while (right < heightsSize) {
            if (heights[right] > nowHeight) {
                break;
            }
            if (heights[right] < nowHeight) {
                lowHeightPos = right;
                nowHeight = heights[right];
            }
            right++;
        }
        if (lowHeightPos > K) {
            heights[lowHeightPos]++;
            continue;
        }
        heights[K]++;
    }
    *returnSize = heightsSize;
    memcpy(ans, heights, sizeof(int) * heightsSize);
    return ans;
}
```
