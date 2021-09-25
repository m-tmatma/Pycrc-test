#include <stdio.h>
#include <string.h>
#include "crc.h"

#define MAX_DATA_LEN 1024

crc_t get_crc(const unsigned char* data, size_t data_len)
{
    crc_t crc = crc_init();
    crc = crc_update(crc, data, data_len);
    crc = crc_finalize(crc);
    return crc;
}

void main(void)
{
    const char * data[] = {
        "ABC",
        "12345",
    };

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
    {
        printf("%s: %08lx\n", data[i],
            get_crc(data[i], strlen(data[i]))
        );
    }
}
