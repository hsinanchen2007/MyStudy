```

/**
*
*总体思路：
*1.遍历单词，对每个字母进行解码，对解码结果进行判断，
*2.遍历缓冲区，判断是否为新增解码序列，如果是，则存入缓冲区，
*3.否则继续解码
*
*/

//to confirm the string of tmp whether in the bufer
int checkComplicate( char ** s , int sSize , char * tmp ){

    for( int i = 0 ; i < sSize ; i++ ){

        if( strcmp( *( s + i ) , tmp ) == 0 ){

            //in the string 
            return 0;

        }

    }   

    //not in the string
    return 1;

}

int uniqueMorseRepresentations(char ** words, int wordsSize){

    //the table according to the characters sequence
    char table[][ 5 ] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    char ** code = ( char ** )malloc( sizeof( char ) * 5 * 1200 );
    char * tmp ;
    int len = 0;

    for( int i = 0 ; i < wordsSize ; i++ ){

        //svae current string 
        tmp = ( char * )malloc( sizeof( char ) * 12 * 5 );
        strcpy( tmp , "" );

        for( int j = 0 ; j < strlen( *( words + i ) ) ; j++ ){
            
            strcat( tmp , table[ ( int )( *( *( words + i ) + j ) ) - 97 ] );

        }

        //add the new sequence to the string buffer
        if( checkComplicate( code , len , tmp ) ){

            *( code + len++ ) = tmp;

        }

    }

    return len;

}
```
