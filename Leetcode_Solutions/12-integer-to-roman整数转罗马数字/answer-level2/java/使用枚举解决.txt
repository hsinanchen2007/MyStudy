 使用枚举，就能满足题目要求了。

class Solution {
    public String intToRoman(int num) {
        if(num < 1 || num > 3999){
            return "";
        }

        StringBuilder result = new StringBuilder();

        for(romeNumber e : romeNumber.values()){
            int digital = num / e.number;
            for(int i = 0; i < digital; i++){
                result.append(e.name());
            }
            num %= e.number;
            
            if(num <= 0){
                break;
            }
        }

        return result.toString();
    }
}
enum romeNumber{
    M(1000),
    CM(900),
    D(500),
    CD(400),
    C(100),
    XC(90),
    L(50),
    XL(40),
    X(10),
    IX(9),
    V(5),
    IV(4),
    I(1)
    ;

    int number;

    romeNumber(int number) {
        this.number = number;
    }
}