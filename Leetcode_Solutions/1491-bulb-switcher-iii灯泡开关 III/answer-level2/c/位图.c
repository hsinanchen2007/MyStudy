# 解法1：位图
## 算法描述
维护一个点亮的灯的位图，和一个左开又闭区间\[start，end)。
每次有一个新灯泡点亮时：
* 设置灯泡所在位置的bit。
* 更新end：end = max(end, light[i])
测试\[start, end)中的灯是否全部点亮，
若点亮，则结果+1。由于已变蓝的灯不需要再考虑，所以把start更新为end的值。

## 复杂度分析
令灯数量为n：
时间复杂度：O（n^2）
空间复杂度：O（n）

## 提交结果
通过

## 参考代码
```
void bitmap_set(unsigned int *bmp, int pos) {
    unsigned int i = pos / 32;
    unsigned int b = pos % 32;
    bmp[i] |= (1UL << b);
    return;
}

bool bmp_test(unsigned int *bmp, int start, int end) {
    for (int i = start / 32; i < end / 32; i++) {
        if (bmp[i] != 0xFFFFFFFFUL) {
            return false;
        }
    }

    if (end % 32) {
        int k = end / 32;
        if (bmp[k] != (1UL << end % 32) - 1) {
            return false;
        }
    }

    return true;
}

int numTimesAllBlue(int* light, int lightSize){
    int size = (lightSize+31)/32;
    unsigned int bmp[size];
    memset(bmp, 0, sizeof(int)*size);

    int result = 0;
    int start = 0;
    int end = light[0];
    for (int i = 0; i < lightSize; i++) {
        bitmap_set(bmp, light[i]-1);
        end = end > light[i] ? end : light[i];
        if (bmp_test(bmp, start, end)) {
            result++;
            start = end;
        }
    }

    return result;
}
```