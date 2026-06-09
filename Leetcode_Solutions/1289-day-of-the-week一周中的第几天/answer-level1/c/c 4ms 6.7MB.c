```
char * dayOfTheWeek( int day , int month , int year ){

    if( month == 1 || month == 2 ){

        month += 12;
        year--;

    } 

    switch( ( day + 2 * month + 3 * ( month + 1 ) / 5 + year + year / 4 - year / 100 + year / 400) % 7 ){   

        case 0:{

            return "Monday";

        }

        case 1:{

            return "Tuesday";

        }

        case 2:{

            return "Wednesday";

        }

        case 3:{

            return "Thursday";

        }

        case 4:{

            return "Friday";

        }

        case 5:{

            return "Saturday";

        }

        default:{

            return "Sunday";

        }

    }
	
    return "";

}
```
