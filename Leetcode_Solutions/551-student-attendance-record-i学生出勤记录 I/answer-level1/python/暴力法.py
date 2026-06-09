```javascript []
```
bool checkRecord(char * s){
    int A = 0;
    int L = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == 'A') {
            if (A < 1) {
                A++;
                L = 0;
            }
            else {
                return false;
            }
        }
        else if (s[i] == 'L') {
            if (L < 2) {
                L++;
            }
            else {
                return false;
            }
        }
        else {
            L = 0;
        }
        i++;
    }
    return true;
}
```
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
