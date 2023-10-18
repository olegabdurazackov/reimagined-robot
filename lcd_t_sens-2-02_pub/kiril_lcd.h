/*------------------------------------------*/
/* Коструктор кирилических символов для LCD */
/* author : Abdurazakov Oleg <olab@email.su>*/
/*------------------------------------------*/

const byte bl[8] ={ // Л
  B00011,
  B00101,
  B01001,
  B01001,
  B01001,
  B01001,
  B11001,
  B00000
};
const byte bo[8] ={ // градусы C
  B00110,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
const byte bb[8] ={ // Б
  B11111,
  B10000,
  B10000,
  B11110,
  B10001,
  B10001,
  B11110,
  B00000
};
const byte bg[8] ={ // Г
  B11111,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B00000
};
const byte bd[8] ={ // Д
  B00110,
  B01010,
  B01010,
  B01010,
  B01010,
  B01010,
  B11111,
  B10001
};
const byte bgg[8] ={ // Ж
  B10101,
  B10101,
  B10101,
  B01110,
  B10101,
  B10101,
  B10101,
  B00000
};
const byte bi[8] ={ // И
  B10001,
  B10001,
  B10011,
  B10101,
  B11001,
  B10001,
  B10001,
  B00000
};
const byte bii[8] ={ // Й
  B00100,
  B10101,
  B10011,
  B10101,
  B11001,
  B10001,
  B10001,
  B00000
};
const byte bz[8] ={ // З
  B01110,
  B10001,
  B00001,
  B00110,
  B00001,
  B10001,
  B01110,
  B00000
};
const byte bp[8] ={ // П
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B00000
};
const byte bu[8] ={ // У
  B10001,
  B10001,
  B10001,
  B01111,
  B00001,
  B00001,
  B11110,
  B00000
};
const byte bf[8] ={ // Ф
  B00100,
  B01110,
  B10101,
  B10101,
  B10101,
  B01110,
  B00100,
  B00000
};
const byte bch[8] ={ // Ч
  B10001,
  B10001,
  B10001,
  B10001,
  B01111,
  B00001,
  B00001,
  B00000
};
const byte bc[8] ={ // Ц
  B10010,
  B10010,
  B10010,
  B10010,
  B10010,
  B10010,
  B11111,
  B00001
};
const byte bsh[8] ={ // Ш
  B10001,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B11111,
  B00000
};
const byte btsh[8] ={ // Щ
  B10001,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B11111,
  B00001
};
const byte be[8] ={ // Э
  B11100,
  B00010,
  B00001,
  B11111,
  B00001,
  B00010,
  B11100,
  B00000
};
const byte byu[8] ={ // Ю
  B10010,
  B10101,
  B10101,
  B11101,
  B10101,
  B10101,
  B10010,
  B00000
};
const byte bya[8] ={ // Я
  B01111,
  B10001,
  B10001,
  B01111,
  B00101,
  B01001,
  B10001,
  B00000
};
const byte btz[8] ={ // Ъ
  B11000,
  B01000,
  B01000,
  B01110,
  B01001,
  B01001,
  B01110,
  B00000
};
const byte byy[8] ={ // Ы
  B10001,
  B10001,
  B10001,
  B11001,
  B10101,
  B10101,
  B11001,
  B00000
};
