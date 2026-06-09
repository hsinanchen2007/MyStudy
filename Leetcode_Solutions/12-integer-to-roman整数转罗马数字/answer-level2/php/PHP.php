感觉php的解法太少了，虽然写的不好，但也不失为一个解法
```
function intToRoman($num) {
        $string = '';
        $per = ["","I","II","III","IV","V","VI","VII","VIII","IX"];
        $ten = ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"];
        $hundred = ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"];
        $thousand = ["","M","MM","MMM"];

        $a = $num / 1000;
        $b = $num / 100 % 10;
        $c = $num / 10 % 10;
        $d = $num % 10;

        $string .= $thousand[$a];
        $string .= $hundred[$b];
        $string .= $ten[$c];
        $string .= $per[$d];
        return $string;

    }
```
