```

char * subString( char * str1 , char * str2 , int len1 , int len2 ){


    int len = len2;

    for( ; len2 > 0 ; len2-- ){

        int flag = 1;

        for( int i = 0 ; i < len1 ; i += len2 ){    

            for( int m = i , n = 0 ; m < len1 && n < len2 ; m++ , n++ ){

                if( *( str1 + m ) != *( str2 + n ) ){

                    flag = 0;
                    break;

                }

            }

        }

        if( flag == 1 && len1 % len2 == 0 && len % len2 == 0 ){

            *( str2 + len2 ) = '\0';
            return str2;

        }

    }

    *( str2 + len2 ) = '\0';

    return str2;

}

char * gcdOfStrings( char * str1 , char * str2 ){

    int len1 = strlen( str1 );
    int len2 = strlen( str2 );

    if( len2 > len1 ){

        return subString( str2 , str1 , len2 , len1 );

    }

    return subString( str1 , str2 , len1 , len2 );

}
```
