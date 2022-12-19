```
    vector<int> twoSum(vector<int>& numbers, int target) {
    int x = 0;
    int y = numbers.size() - 1;

    while ((numbers[x] + numbers[y]) != target && x < y){
        if (abs((numbers[x] + numbers[y - 1]) - target ) < abs((numbers[x + 1] + numbers[y]) - target))
            y --;
        else
            x ++;
    }

    vector<int> result{x + 1, y + 1};
    return result;

    }
```
