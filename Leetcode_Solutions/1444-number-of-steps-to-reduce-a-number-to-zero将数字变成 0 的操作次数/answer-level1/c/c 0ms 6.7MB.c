```
int numberOfSteps (int num){

    int count = 0;

    while( num > 0 ){

        count++;

        if( num % 2 == 0 ){

            num /= 2;
            continue;

        }

        num--;

    }

    return count;

}
```
