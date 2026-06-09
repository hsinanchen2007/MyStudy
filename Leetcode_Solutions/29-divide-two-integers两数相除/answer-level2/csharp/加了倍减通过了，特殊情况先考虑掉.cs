public static int Divide(int dividend, int divisor)
        {
            if (divisor == 1) return dividend;
            if (divisor == -1)
            {
                if (dividend == int.MinValue) return int.MaxValue;
                else  return -dividend;
            }
            double Dividend = dividend;
            double Divisor = divisor;
            if (Dividend == 0) return 0;
            string strfuhao = "";
            if (Dividend < 0)
            {
                Dividend = -Dividend; strfuhao += "-";
            }
            if (Divisor < 0)
            {
                Divisor = -Divisor; strfuhao += "-";
            }
            if (strfuhao == "--") strfuhao = "";
            if (Dividend < Divisor) return 0;
            if (Dividend == Divisor) return Convert.ToInt32(strfuhao + "1");
            //
            double count = 0;
            int cifang = 0;
            HERE:
            double jieguo1 = Dividend - Divisor * Math.Pow(2,cifang);
            
            if (jieguo1 >= 0)
            {
                count += Math.Pow(2, cifang);
                cifang++;
                Dividend = jieguo1;
                goto HERE;
            }
            else if (jieguo1 < 0)
            {
                count += Divide(Convert.ToInt32(Dividend), Convert.ToInt32(Divisor));
            }

            if (count > int.MaxValue)
            {
                return int.MaxValue;
            }
            else
            {
                return Convert.ToInt32(strfuhao + count);
            }
        }