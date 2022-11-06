#include <stdio.h>
int main()
{
    int N, a, b, c;
    int try_1, try_2, try_3, try_4;
    int guess_1, guess_2, guess_3, guess_4;
    int guess[10], hit[10], match[10];//保存读入数据
    int guess_tmp, hit_tmp, match_tmp;
    int guess_cnt[10], try_cnt[10];
    int i, j, satisfy, notsure;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        guess[i] = a;
        hit[i] = b;
        match[i] = c;
    }
    notsure = 1;//flag

    // 枚举所有可能的结果
    for (try_1 = 0; try_1 <= 9; try_1++)
        for (try_2 = 0; try_2 <= 9; try_2++)
            for (try_3 = 0; try_3 <= 9; try_3++)
                for (try_4 = 0; try_4 <= 9; try_4++)
                {
                    satisfy = 0;
                    // 遍历所有条件，看能不能都满足，反正满足一次就+1，最后等于N就表示满足
                    for (i = 0; i < N; i++)
                    {
                        guess_tmp = guess[i];
                        guess_4 = guess_tmp % 10;
                        guess_tmp /= 10;
                        guess_3 = guess_tmp % 10;
                        guess_tmp /= 10;
                        guess_2 = guess_tmp % 10;
                        guess_tmp /= 10;
                        guess_1 = guess_tmp % 10;
                        // 初始化
                        for (j = 0; j <= 9; j++)
                        {
                            guess_cnt[j] = 0;
                            try_cnt[j] = 0;
                        }
                        //数组：计数器
                        guess_cnt[guess_1]++;
                        guess_cnt[guess_2]++;
                        guess_cnt[guess_3]++;
                        guess_cnt[guess_4]++;
                        try_cnt[try_1]++;
                        try_cnt[try_2]++;
                        try_cnt[try_3]++;
                        try_cnt[try_4]++;

                        // 看个数符合要求的有多少个
                        hit_tmp = 0;
                        for (j = 0; j <= 9; j++)
                            if (guess_cnt[j] <= try_cnt[j])
                                hit_tmp += guess_cnt[j];
                            else
                                hit_tmp += try_cnt[j];

                        // 看位置符合要求的有多少个
                        match_tmp = 0;
                        if (guess_1 == try_1)
                            match_tmp++;
                        if (guess_2 == try_2)
                            match_tmp++;
                        if (guess_3 == try_3)
                            match_tmp++;
                        if (guess_4 == try_4)
                            match_tmp++;

                        // 如果真的满足，那么就说明满足了一个条件
                        if (hit_tmp == hit[i] && match_tmp == match[i])
                            satisfy++;
                    }

                    if (satisfy == N)
                    {
                        printf("%d%d%d%d", try_1, try_2, try_3, try_4);
                        notsure = 0;
                    }
                }

    if (notsure)
        printf("Not sure");
}
