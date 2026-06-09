大家都说从开头比较不行，我就不信。
```
class Solution {
    public int minArray(int[] numbers) {
        if(numbers == null || numbers.length < 0) {
            return -1;
        }
        int i = 0;
        int j = numbers.length - 1;

        while(i < j){
            int m = (i + j) /2;
            if(numbers[i] > numbers[m]){
                j = m;
                continue;
            }

            if(numbers[i] < numbers[m]){
                if(numbers[i] < numbers[j]){
                    break;
                }else{
                    i = m+1;
                    continue ;
                }
            }

            if(numbers[i] == numbers[m]){
                if(i != m){
                    i++;
                }else{
                    if(numbers[i] < numbers[j]){
                        break;
                    }else{
                        i = m+1;
                    }
                }
            }
        }

        return numbers[i];
    }
}
```
我还要写两种方式，上面是我女票写的，下面是我写的。
```
class Solution {
    public int minArray(int[] numbers) {
        if(numbers == null || numbers.length < 0) {
            return -1;
        }
        int left = 0;
        int right = numbers.length - 1;
        int mid = (right + left ) /2;
        while(left < right) {
            if(numbers[mid] < numbers[left]) {
                right = mid;
            } else if(numbers[mid] > numbers[left]) {
                if(numbers[left] < numbers[right]) {
                    return numbers[left];
                }
                left = mid + 1;
            } else {
                if(numbers[left] > numbers[right]) {
                    left ++;
                } else {
                    right --;
                }
            }
            mid = (right + left ) /2;
        }
        return numbers[mid];
    }
}
```


