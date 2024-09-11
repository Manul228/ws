#include <stddef.h>
#include <stdint.h>

struct efi_table_header
{
    uint64_t signature;
    uint32_t revision;
    uint32_t header_size;
    uint32_t crc32;
    uint32_t reserved;
};

struct efi_system_table
{
    struct efi_table_header header;
    uint16_t *unused1;
    uint32_t unused2;
    void *unused3;
    void *unused4;
    void *unused5;
    struct efi_simple_text_output_protocol *out;
    void *unused6;
    void *unused7;
    void *unused8;
    void *unused9;
    uint64_t unused10;
    void *unused11;
};

typedef uint64_t efi_status_t;
typedef uint64_t efi_uint_t;

struct efi_simple_text_output_protocol
{
    void (*unused1)();

    efi_status_t (*output_string)(
        struct efi_simple_text_output_protocol *,
        uint16_t *);

    void (*unused2)();
    void (*unused3)();
    void (*unused4)();
    void (*unused5)();

    efi_status_t (*clear_screen)(
        struct efi_simple_text_output_protocol *);

    void (*unused6)();
    void (*unused7)();

    void *unused8;
};

typedef void *efi_handle_t;

efi_status_t efi_main(
    efi_handle_t handle, struct efi_system_table *system_table)
{
    uint16_t msg[] = u"Some string\n";
    efi_status_t status;

    status = system_table->out->clear_screen(system_table->out);
    if (status != 0)
        return status;

    status = system_table->out->output_string(system_table->out, msg);
    if (status != 0)
        return status;

    return 0;
}
