#include "dictP.h"

static const wint_t start [] = {
     48,     65,     97,    170,    181,    186,    192,    216,
    248,    444,    452,    546,    592,    902,    904,    908,
    910,    931,    976,   1024,   1162,   1232,   1272,   1280,
   1329,   1377,   1632,   1776,   2406,   2534,   2662,   2790,
   2918,   3047,   3174,   3302,   3430,   3664,   3792,   3872,
   4160,   4256,   4969,   6112,   6160,   7680,   7840,   7936,
   7960,   7968,   8008,   8016,   8025,   8027,   8029,   8031,
   8064,   8118,   8126,   8130,   8134,   8144,   8150,   8160,
   8178,   8182,   8305,   8319,   8450,   8455,   8458,   8469,
   8473,   8484,   8486,   8488,   8490,   8495,   8499,   8505,
   8509,   8517,  64256,  64275,  65296,  65313,  65345,  66560,
  66600, 119808, 119894, 119966, 119970, 119973, 119977, 119982,
 119995, 119997, 120002, 120005, 120071, 120077, 120086, 120094,
 120123, 120128, 120134, 120138, 120146, 120488, 120514, 120540,
 120572, 120598, 120630, 120656, 120688, 120714, 120746, 120772,
};

static const int count [] = {
     10,     26,     26,      1,      1,      1,     23,     31,
    195,      4,     93,     18,     94,      1,      3,      1,
     20,     44,     38,    130,     69,     38,      2,     16,
     38,     39,     10,     10,     10,     10,     10,     10,
     10,      9,     10,     10,     10,     10,     10,     10,
     10,     38,      9,     10,     10,    156,     90,     22,
      6,     38,      6,      8,      1,      1,      1,     31,
     53,      7,      1,      3,      7,      4,      6,     13,
      3,      7,      1,      1,      1,      1,     10,      1,
      5,      1,      1,      1,      4,      3,      2,      1,
      3,      5,      7,      5,     10,     26,     26,     38,
     38,     85,     71,      2,      1,      2,      4,     12,
      1,      4,      2,     65,      4,      8,      7,     28,
      4,      5,      1,      7,    338,     25,     25,     31,
     25,     31,     25,     31,     25,     31,     25,      6,
};

#define ARRAY_SIZE (sizeof (start) / sizeof (start [0]))

int iswalnum__ (wint_t wc);

int iswalnum__ (wint_t wc)
{
   const wint_t *l = start;
   const wint_t *r = start + ARRAY_SIZE;
   const wint_t *s = NULL;

   if (wc == WEOF)
      return 0;

   while (l < r) {
      s = l + ((r - l) >> 1);

      if (*s <= wc){
	 l = s + 1;
      }else{
	 r = s;
      }
   }

   --l;
   if (l < start)
      return 0;

   if (wc < l [0] + count [l - start])
      return 1;
   else
      return 0;
}
