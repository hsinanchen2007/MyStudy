

java
```java
class Solution {
    public boolean judgeCircle(String moves) {
        int o = 0;
        int v = 0;

        for(int i = 0; i < moves.length(); i++) {
            switch(moves.charAt(i)) {
                case 'L':
                    o--;
                    break;
                case 'R':
                    o++;
                    break;
                case 'U':
                    v++;
                    break;
                case 'D':
                    v--;
                    break;
            }
        }

        return o == 0 && v == 0;
    }
}
```

js
```js
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    var o = 0;
    var v = 0;
    
    for(var i = 0; i < moves.length; i++) {
        switch(moves[i]) {
            case "L":
                o--;
                break;
            case "R":
                o++;
                break;
            case "U":
                v++;
                break;
            case "D":
                v--;
                break;
        }
    }
    
    return !o && !v;
};
```